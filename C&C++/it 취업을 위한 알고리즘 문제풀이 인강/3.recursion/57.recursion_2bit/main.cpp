#include <stdio.h>

// x를 받아 2진수화 
void D(int x){

    // 종료조건 x==0
    if(x==0) return;

    // 
    else{
        D(x/2);
        printf("%d", x%2);
    }
    

}

int main(){

    int n;
    scanf("%d", &n);

    D(n);

    return 0;

}