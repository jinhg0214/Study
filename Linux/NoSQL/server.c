#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#define MAX 256

// 자료구조는 구조체 이용
struct data{
        char key[MAX];
        char value[MAX];
} db[MAX];
int db_size = 0;

pthread_t t1, t2;

FILE* db_fp;

int fd, new_fd = -1;
int flag = 0;

char response[MAX];
char buf[MAX];

int init(){
        int ret = 0;

        // 1. socket
        fd = socket(AF_INET, SOCK_STREAM, 0);
        if(fd == -1) {
                printf("ERROR :: SOCKET Create Failed\n");
                return -1;
        }

        // 2. binding
        struct sockaddr_in addr = {0};
        addr.sin_family = AF_INET;
        addr.sin_port = htons(12345);
        addr.sin_addr.s_addr = 0; // localhost

        ret = bind(fd, (struct sockaddr *)&addr, sizeof(struct sockaddr));
        if(ret == -1) return ret;

        // 3. listen state
        ret = listen(fd, 2);
        if (ret == -1) return ret;

        return ret;
}

void bye(){
        printf("SERVER :: BYE\n");
        printf("SERVER :: bye :: Send client shutdown signal\n");
        shutdown(new_fd, SHUT_WR); // send 0 (EOF);

        close(new_fd);
        close(fd);
        printf("SERVER :: bye :: File pointer closed\n");

        new_fd = -1;
        fd = -1;

        printf("SERVER :: DB_UPDATE\n");
        // db update
        db_fp = fopen("./db.txt", "w+");
        for(int i=0; i<db_size; i++){
                fprintf(db_fp, "%s:%s\n", db[i].key, db[i].value);
        }
        fclose(db_fp);

        exit(0);
}

int find_db(char* key){
        int ret = -1;
        for(int i=0; i<db_size; i++){
                if( !strcmp(db[i].key, key) ){
                        ret = i;
                        break;
                }
        }
        return ret;
}

void add_db(char* buf){
        // printf("buf : %s\n", buf);
        char key[MAX];
        char value[MAX];
        memset(key, 0, sizeof(key));
        memset(value, 0, sizeof(value));

        int a = -1;
        int b = -1;
        for(int i=0; buf[i] != '\0'; i++){
                if( buf[i] == ' '){
                        a = i;
                }
                if( buf[i] == ':'){
                        b = i;
                        break;
                }
        }

        strncpy(key, buf + a + 1, b -a -1);
        strcpy(value, buf+ b + 1);
        value[strlen(value) - 1]= '\0';

        //  already exist
        int pos = find_db(key);
        memset(response, 0, sizeof(response));
        if( pos != -1 ){
                strcpy(db[pos].value, value);
        }
        else{ // if there is no collision
                strcpy(db[db_size].key, key);
                strcpy(db[db_size].value, value);
                db_size++;
        }
        strcpy(response, "SAVE OK");
        write(new_fd, response, sizeof(response));
}


void read_db(char* buf){
        char key[MAX];
        memset(key, 0, sizeof(key));

        int a =-1;
        int b = -1;
        for(int i=0; buf[i] != '\0'; i++){
                if( buf[i] == ' '){
                        a = i;
                        break;
                }
        }

        strcpy(key, buf + a + 1);
        key[strlen(key) - 1] = '\0';

        printf("key:[%s]\n",  key);

        int pos = find_db(key);
        memset(response, 0, sizeof(response));

        if( pos != -1 ){
                printf("[%s]:[%s]\n", db[pos].key, db[pos].value);
                strcpy(response, "KEY:[");
                strcat(response, db[pos].key);
                strcat(response, "], VALUE:[");
                strcat(response, db[pos].value);
                strcat(response, "]\n");

                write(new_fd, response, sizeof(response));

        }

        else{
                // send response that there is no such key on db
                printf("SERVER :: read_db :: There is no such key on db\n");
                strcpy(response,"READ FAILED :: There is no such value");
                write(new_fd, response, sizeof(response));
        }
}

void clear_db(){
        db_size = 0;
        memset(response, 0, sizeof(response));
        strcpy(response, "CLEAR OK");
        write(new_fd, response, sizeof(response));
}

void* chat_read(){
        while(new_fd != -1){ // if connected with server, then continuously read.
                memset(buf, 0, sizeof(buf));
                read(new_fd, buf, sizeof(buf));

                // client session off
                if( !strcmp(buf, "CLIENT_DISCONNECTED")){
                        printf("SERVER :: User left channel\n");
                        close(new_fd);
                        flag = 1;
                        return 0;
                }

                char cmd[6];
                strncpy(cmd, buf, 5);

                // cmd :: save
                if( !strcmp(cmd,"save ") || !strcmp(cmd,"SAVE ")){
                        add_db(buf);
                }
                // cmd :: read
                else if( !strcmp(cmd, "read ") || !strcmp(cmd, "READ ") ){
                        read_db(buf);
                }
                // cmd :: clear
                else if( !strcmp(cmd, "clear") || !strcmp(cmd, "CLEAR") ) {
                        clear_db();
                }
                else if( !strcmp(cmd, "debug") || !strcmp(cmd, "DEBUG")) {
                        printf("=============\n");
                        for(int i=0; i<db_size; i++){
                                printf("key:[%s], value:[%s]\n", db[i].key, db[i].value);
                        }
                        printf("=============\n");
                }
        }
}

void* chat_write(){
        while(new_fd != -1){
                if(flag == 1) break;
                memset(buf, 0, sizeof(buf));
                fgets(buf, 100, stdin); // scanf X
                write(new_fd, buf, sizeof(buf));
                usleep(100 * 1000);
        }
}

int main(){
        signal(SIGINT, bye);

        int ret = init();
        if(ret == -1) {
                printf("[%s :: %d] ERROR : INIT ERROR", __FILE__, __LINE__);
        }

        // db read
        db_fp = fopen("db.txt", "r+");
        if(db_fp < 0) {
                printf("[%s :: %d] ERROR : db.txt open Failed\n", __FILE__, __LINE__);
                exit(1);
        }

        char buf[MAX];
        while(1){
                if(fgets(buf, MAX, db_fp) == NULL) break;
                add_db(buf);
        }
        fclose(db_fp);

        struct sockaddr new_addr = {0};
        int len;

        // loop
        while(1){
                flag = 0;
                printf("START\n");

                new_fd = accept(fd, &new_addr, &len);
                close(fd); // temporaly closed
                printf("new user joined \n");
                pthread_create(&t1, NULL, &chat_read, NULL);
                pthread_create(&t2, NULL, &chat_write, NULL);

                pthread_join(t1, NULL);
                pthread_join(t2, NULL);

                sleep(1);
        }

        return 0;
}