#include <stdio.h>

/*
nM¥�� ��Ʈ��ũ ���� 1, 2m�� �ڸ� ���

f(1) = 1
f(2) = 2
...
f(n) = f(n-2)+f(n-1) 


*/

int dy[50];

int main(){
    int n;

    scanf("%d", &n);

    dy[1]=1; // 1m�� �ڸ��� ��� -> 1����
    dy[2]=2; // 2m�� �ڸ��� ��� -> 2����

    for(int i=3; i<=n; i++){ // 3m~Nm����
        dy[i]=dy[i-2]+dy[i-1]; // ��ȭ��
    }

    printf("%d", dy[n]); 
    return 0;
}