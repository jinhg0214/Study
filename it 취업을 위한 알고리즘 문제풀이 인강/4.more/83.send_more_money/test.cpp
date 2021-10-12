#include <stdio.h>

/*
����� ����
DFS�� �̿��� �� �ܾ �����ϴ� ���ڸ� ã�� 

a 0 1 2 3 4 5 6 7 
  D E M N O R S Y
*/

int a[10], ch[10];

int send(){
    return a[6] * 1000 + a[1] * 100 + a[3] * 10 + a[0];
}

int more(){
    return a[2] * 1000 + a[4] * 100 + a[5] * 10 + a[1];
}

int money(){
    return a[2]*10000 + a[4] * 1000 + a[3] * 100 + a[1]*10 + a[7];
}

void DFS(int L){
    if(L == 8){
        if(a[2]==0 || a[6]== 0) return;
        if(send() + more() == money()){
            printf("  %d %d %d %d\n", a[6], a[1], a[3], a[0]);
            printf("+ %d %d %d %d\n", a[2], a[4], a[5], a[1]);
            printf("----------\n");
            printf("%d %d %d %d %d\n", a[2], a[4], a[3], a[1], a[7]);
        }
    }
    else{
        for(int i=0; i<10; i++){ // a[L]�� 0~9 ���� �־
            if(ch[i] == 0){

            a[L] = i;

            ch[i]=1;
            DFS(L+1);
            ch[i]=0;
        }
        }
        
    }
}

int main(){

    DFS(0); // level 0 ���� ����

    return 0;
}