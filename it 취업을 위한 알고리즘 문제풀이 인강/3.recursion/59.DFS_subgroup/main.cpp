#include <stdio.h>

int n, chk[11]; // 체크 배열, 출력할지 말지 결정함

void DFS(int L){
    // 종료지점(Level+1)
    if(L == n+1){
        for(int i=1; i<=n; i++){
            if(chk[i]==1){ // 체크 배열이 1인 경우 출력한다.
                printf("%d ", i);
            }
        }
        puts("");
    } 
    else {
        chk[L] = 1; // 현재 노드가 참여하는 경우
        DFS(L+1);   // 왼쪽 자식으로 이동
        
        chk[L] = 0; // 현재 노드가 참여하지 않는 경우
        DFS(L+1);   // 오른쪽 자식 
    }

}

int main(){

    scanf("%d", &n);
    
    DFS(1);
    return 0;
}