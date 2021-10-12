#include <stdio.h>

int n, t[16], p[16], res = -2147000000;

void DFS(int L, int sum){

    if(L==n+1){ // 마지막 날에 도달한 경우 기존 res 값과 비교
        if(sum > res) res = sum;
    } 
    
    else {
        if(L+t[L] <= n+1){ // 날짜를 넘어가지 않도록 
            DFS(L+t[L], sum + p[L]); // 하고 다음날로
        }
        DFS(L+1, sum); // 안하고 다음날로 

    }
}

int main(){
    freopen("G:\\Git\\Algorithm-C-\\4.more\\84.vacation\\input.txt", "rt", stdin);

    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        scanf("%d %d", &t[i], &p[i]);
    }

    DFS(1, 0);

    printf("%d", res);
    return 0;

}