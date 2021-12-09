#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#define MAX 256

pthread_t t1, t2;
int fd;
int flag = 0;

char buf[MAX];

// ipaddr에 연결한다
int init(char* ipaddr){
	int ret = 0;

	printf("ip : %s\n", ipaddr);

	// 1. socket 
	fd = socket(AF_INET, SOCK_STREAM, 0);
	if(fd == -1) {
		printf("[%s :: %d] ERROR : Socket Create Failed\n", __FILE__, __LINE__);
		return -1;
	}

	// 2. connect
	struct sockaddr_in addr = {0};
	addr.sin_family = AF_INET;
	addr.sin_port = htons(12345);
	addr.sin_addr.s_addr = inet_addr(ipaddr);

	ret = connect(fd, (struct sockaddr *)&addr, sizeof(addr));
	if(ret == -1) {
		printf("[%s :: %d] ERROR : Connect Failed \n", __FILE__, __LINE__);
		return ret;
	}
	return ret;
}

void bye(){
	printf("\nCLIENT :: Exit program\n");
	
	// 종료시 서버에 종료한다고 보내야한다
	// 서버에서는 이 특정 문자열을 받으면 세션을 꺼버린다
    memset(buf, 0, sizeof(buf));
    strcpy(buf, "CLIENT_DISCONNECTED");

	write(fd, buf, sizeof(buf));

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	
	close(fd);

	exit(1);
}

void * chat_read(){
	while(fd != -1){
		memset(buf, 0, sizeof(buf));
		int readCnt = read(fd, buf, sizeof(buf));
		if(readCnt == 0) {
			flag = 1;
			bye();
		}
		if(buf[0] != 0) 
			printf("FROM SERVER : %s\n", buf);
		usleep(100 * 1000);
	}
}

void * chat_write(){
	char tmp[5];
	while(fd != -1){
		memset(buf, 0, sizeof(buf));
        memset(tmp, 0, sizeof(tmp));
		fgets(buf, 100, stdin);
		
		// exit cmd chk
		strncpy(tmp, buf, 4);
		tmp[4] ='\0';

		if( !strcmp(tmp, "exit") || !strcmp(tmp, "EXIT")){
			bye();
		}

		write(fd, buf, sizeof(buf));
		usleep(100 * 1000);
	}
}

int main(){
	signal(SIGINT, bye);
	
	printf("ENTER DB IP >> ");
	char ipaddr[MAX];
	scanf("%s", &ipaddr);

	int ret = init(ipaddr);
	if(ret == -1){
		printf("[CONNECTION FAILED] : INIT ERROR\n");
		return 1;
	}

	printf("==DB Server connected==\n");
	
	pthread_create(&t1, NULL, &chat_read, NULL);
	pthread_create(&t2, NULL, &chat_write, NULL);

	while(1){
		if(flag == 1) break;
	}

	return 0;
}