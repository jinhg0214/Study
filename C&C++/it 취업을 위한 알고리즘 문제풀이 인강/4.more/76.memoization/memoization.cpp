#include <stdio.h>

/*
5C3 = 4C2(내가 뽑히고, 나를 제외한 4명이서 나머지 2자리 경합) + 4C3 (내가 뽑지히 않고, 3자리 경합)
...
nCr = (n-1)C(r-1) + (n-1)C(r)
*/
int dy[21][21]={0}; // 메모를 위한 결과값 저장하기

int DFS(int n, int r){
    if(dy[n][r] > 0) return dy[n][r]; // 저장된 결과값이 존재할 경우 (시간 절약)
    if(r==0 || n==r) return 1;
    else 
        // 결과 값을 dy에 저장하면서 리턴함
        return dy[n][r]=DFS(n-1,r-1)+DFS(n-1,r); 
}

int main(){
    int n, r;
    scanf("%d %d", &n, &r);

    printf("%d\n", DFS(n,r));
    return 0;
}