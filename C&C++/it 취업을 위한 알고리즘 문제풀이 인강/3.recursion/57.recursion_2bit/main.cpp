#include <stdio.h>

// x�� �޾� 2����ȭ 
void D(int x){

    // �������� x==0
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