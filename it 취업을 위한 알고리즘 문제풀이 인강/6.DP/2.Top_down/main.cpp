#include <stdio.h>

int dp[101]={0}; // memoization

int DFS(int n){
    if(dp[n] > 0) return dp[n]; // �޸� ����� ���� �ִٸ� ����
    if(n == 1 || n == 2) return n;
    else return dp[n] = DFS(n-1) + DFS(n-2);
}

int main(){
    int n;
    scanf("%d", &n);

    printf("%d", DFS(n));

    return 0;
}