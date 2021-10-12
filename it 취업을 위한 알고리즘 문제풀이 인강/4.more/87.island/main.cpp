#include <stdio.h>
#include <queue>

/* BFS 이용
1. 2차원 배열 map에 지도 정보를 읽어들인다
2. map[n][m]1을 만나면 큐에 좌표를 넣고, 상하좌우, 대각선에 1이 있는지 확인
3. 방문한 곳은 0으로 바꾼다(다시 방문하지 않도록)
4. 모든 방향이 0이라면, 큐에 push할 것이 없으므로 끝, 이때 섬의 개수를 하나 추가함.
5. map[n+1][m+1]로 이동 후 반복... map[N][N]까지 탐색해본다 
*/
using namespace std;

int n, map[30][30], cnt=0;
int dx[8]={0, 1, 1, 1, 0, -1, -1, -1}; // 12, 1:30, 3, 4:30, 6, 7:30, 9, 10:30
int dy[8]={-1, -1, 0, 1, 1, 1, 0, -1};

// 좌표 구조체
struct Loc{
    int x;
    int y;
    Loc(int a, int b){
        x=a;
        y=b;
    }
};

queue<Loc> Q; // 좌표를 저장하는 큐

int main(){
    freopen("G:\\Git\\Algorithm-C-\\4.more\\87.island\\input.txt", "rt", stdin);
    int i, j;

    scanf("%d", &n);

    // 맵에 데이터 저장
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            scanf("%d", &map[i][j]);
        }
    }

    // BFS 
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            if(map[i][j]==1){ // 현재 좌표가 땅이라면
                Q.push(Loc(i,j)); // 큐에 현재 좌표 삽입
                map[i][j]=0; // 다시 방문하지 않도록 0으로 바꿈

                while(!Q.empty()){
                    Loc tmp = Q.front();
                    Q.pop();

                    // 큐에 저장된 좌표와 연결된 땅을 찾음
                    for(int k=0; k<8; k++){
                        int xx = tmp.x + dx[k];
                        int yy = tmp.y + dy[k];

                        if(map[xx][yy] == 1){
                            Q.push(Loc(xx, yy));
                            map[xx][yy] = 0;
                        }
                    }
                }
                cnt++;
            }
        }
    }

    printf("%d", cnt);

    return 0;

}