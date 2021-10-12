#include <stdio.h>

/*
nM짜리 네트워크 선을 1, 2m로 자를 방법

f(1) = 1
f(2) = 2
...
f(n) = f(n-2)+f(n-1) 


*/

int dy[50];

int main(){
    int n;

    scanf("%d", &n);

    dy[1]=1; // 1m를 자르는 방법 -> 1가지
    dy[2]=2; // 2m를 자르는 방법 -> 2가지

    for(int i=3; i<=n; i++){ // 3m~Nm까지
        dy[i]=dy[i-2]+dy[i-1]; // 점화식
    }

    printf("%d", dy[n]); 
    return 0;
}