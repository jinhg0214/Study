#include <stdio.h>

/*
  a 0 1 2 3 4 5 6 7   
    D E M N O R S Y
*/

int a[10], ch[10];

int send(){ 
    return a[6]*1000 + a[1]*100 + a[3]*10 + a[0]*1;
}

int more(){
    return a[2]*1000 + a[4]*100 + a[5]*10 + a[1]*1;
}

int money(){
    return a[2]*10000 + a[4]*1000 + a[3]*100 + a[1]*10 + a[7];
}

void DFS(int L){
    // 복면산인지 확인후 출력
    if(L==8){ 
        if(send() + more() == money()){

            if(a[2]==0 || a[6]==0) return; // S 또는 M 이 0인 경우, 복면산이 아니므로 리턴

            printf("   %d %d %d %d\n", a[6], a[1], a[3], a[0]);
            printf(" + %d %d %d %d\n", a[2], a[4], a[5], a[1]);
            printf("----------\n");
            printf(" %d %d %d %d %d\n", a[2], a[4], a[3], a[1], a[7]);
        }
    }
    // 순열을 만드는 과정
    else{
        for(int i=0; i<10; i++){
            if(ch[i]==0){

                a[L]=i; // L번째 자리에 i를 넣어봄

                ch[i]=1;
                DFS(L+1);
                ch[i]=0;
            }
        }
    }

}

int main(){

    DFS(0);
    return 0;

}