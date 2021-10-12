#include <stdio.h>
#include <queue>

/*
최단거리를 dis 배열에 기록
*/
using namespace std;

int n, map[10][10], dis[10][10]={0};
int dx[4]={0, 1, 0, -1};
int dy[4]={-1, 0, 1, 0};

struct Loc{
    int x;
    int y;
    Loc(int a, int b){
        x=a;
        y=b;
    }
};

queue<Loc> Q;

int main(){
    freopen("G:\\Git\\Algorithm-C-\\4.more\\88.maze\\input.txt", "rt", stdin);

    // 지도 입력받기
    for(int i=1; i<=7; i++){
        for(int j=1; j<=7; j++){
            scanf("%d", &map[i][j]);
        }
    }

    // BFS 시작
    Q.push(Loc(1,1)); // (1.1) 에서 시작
    map[1][1]=1; // map 배열에 바로 방문했다고 체크해버림

    while(!Q.empty()){
        Loc tmp = Q.front();
        Q.pop();

        // 현재 위치에서 4방향 이동시도
        for(int i=0; i<4; i++){
            int xx = tmp.x+dx[i];
            int yy = tmp.y+dy[i];

            if(map[xx][yy]==0 && // 좌표에 저장된 값이 0이라면 이동 가능
                xx >= 1 && xx <= 7 && // 범위 내에 있는지 확인
                yy >= 1 && yy <=7 ){
                    Q.push(Loc(xx, yy));
                    map[xx][yy]=1; 
                    dis[xx][yy] = dis[tmp.x][tmp.y] +1; // 중요! 이전 좌표 +1 
                }
        }
    }
    printf("%d", dis[7][7]);

    return 0;

}