#include <stdio.h>

int map[21][21], chk[21], cnt=0, n;

void DFS(int v){
    // 도착지점인지 확인
    if(v == n){
        cnt++;
    } 
    // 아닌경우 재귀호출
    else {
        for(int i=1; i<=n; i++){
            if(map[v][i] == 1 && chk[i]==0){ // v to 1경로가 있고, 방문하지 않았다면 
                chk[i]=1;
                DFS(i);
                chk[i]=0; 
                // 체크를 다시 푸는이유??
                // 다른 재귀함수가 방문할 수 있도록 체크 해제
            }
        }
    }

}

int main(){
    freopen("G:\\Git\\Algorithm-C-\\3.recursion\\64.DFS_search\\input.txt", "rt", stdin);


    int m, start, end;
    scanf("%d %d", &n, &m);

    for(int i=1; i<=m; i++){
        scanf("%d %d", &start, &end);
        map[start][end] = 1;
    }

    chk[1]=1;
    // 1번 노드부터 출발
    DFS(1);

    printf("%d", cnt);

    return 0;
}