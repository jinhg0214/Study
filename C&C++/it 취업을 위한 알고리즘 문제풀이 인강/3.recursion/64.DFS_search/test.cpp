#include <stdio.h>

int matrix[21][21], chk[21], cnt=0, n;

void DFS(int v){

    if(v==n){ // 도착지점에 도달한경우
        cnt++;
    }
    else {
        for(int i=1; i<=n; i++){ // 각 노드들이 연결되어있는지 확인
            if(matrix[v][i] == 1 && chk[i] == 0){  // 연결되어있고, 방문하지 않은 노드인경우
                chk[i]=1;
                DFS(i);
                chk[i]=0;
            }
        }
    }
}

int main(){
    // freopen("G:\\Git\\Algorithm-C-\\3.recursion\\64.DFS_search\\input.txt", "rt", stdin);

    int m, start, end;
    scanf("%d %d", &n, &m);

    for(int i=1; i<=m; i++){
        scanf("%d %d", &start, &end);
        matrix[start][end] = 1;
    }

    chk[1]=1;
    DFS(1); // 1에서 시작하여 n으로 도달할 수 있는 방법의 수

    printf("%d", cnt);

    return 0;
}