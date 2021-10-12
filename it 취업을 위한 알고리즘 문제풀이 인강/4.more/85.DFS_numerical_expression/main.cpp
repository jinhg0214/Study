#include <stdio.h>

int n, a[11], op[5], maxi=-2147000000, mini=2147000000;

void DFS(int L, int res){
    if(L==n){
        if(res > maxi) maxi=res;
        if(res < mini) mini=res;
    }
    else{
        if(op[0] > 0){ // 더하기 남아있는경우
            op[0]--;
            DFS(L+1, res+a[L]);
            op[0]++;
        }  
        if(op[1] > 0){ // 뺄셈
            op[1]--;
            DFS(L+1, res-a[L]);
            op[1]++;
        } 
        if(op[2] > 0){ // 곱하기
            op[2]--;
            DFS(L+1, res*a[L]);
            op[2]++;
        } 
        if(op[3] > 0){ // 나누기
            op[3]--;
            DFS(L+1, res/a[L]);
            op[3]++;
        } 
    }
}

int main(){
    freopen("G:\\Git\\Algorithm-C-\\4.more\\85.DFS_numerical_expression\\input.txt", "rt", stdin);

    int i;

    scanf("%d", &n);

    //n개의 수열 받기
    for(i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    //사칙연산 개수 받기
    for(i=0; i<4; i++){
        scanf("%d", &op[i]);
    }

    // DFS
    DFS(1, a[0]); // 1 level, 첫번째 숫자를 매개변수로 넘김

    printf("%d\n%d\n", maxi, mini);

    return 0;
}