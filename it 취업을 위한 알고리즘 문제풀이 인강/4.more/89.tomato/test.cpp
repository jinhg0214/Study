#include <iostream>
#include <queue>

using namespace std;

int map[1010][1010], dis[1010][1010]={0};
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

struct Loc{
    int x;
    int y;
    Loc(int a, int b){
        x=a;
        y=b;
    }
};

int main(){
    freopen("G:\\Git\\Algorithm-C-\\4.more\\89.tomato\\input.txt", "rt", stdin);

    int n, m;
    queue<Loc> Q;

    cin >> m >> n; 

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> map[i][j];
            if(map[i][j]==1){
                Q.push(Loc(i,j)); // 숙성된 토마토의 좌표를 넣음
            }
        }
    }

    // BFS
    while(!Q.empty()){
        Loc tmp = Q.front();
        Q.pop();

        for(int k=0; k<4; k++){
            int xx = tmp.x + dx[k];
            int yy = tmp.y + dy[k];

            // 경계 처리
            if(xx < 1 || xx > n || yy < 1 || yy > m) continue;

            // 옆자리 토마토가 숙성되었는지 확인
            if(map[xx][yy] == 0){
                Q.push(Loc(xx,yy));

                map[xx][yy] = 1; // 숙성된것으로 처리
                dis[xx][yy] = dis[tmp.x][tmp.y] + 1; // 숙성 거리 저장
            }
        }
    }
    bool flag = true;
    int res = -2147000000; // 최대 숙성일 수를 저장

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(map[i][j]==0) flag = false; // 미숙성 토마토가 있다면 false로
            if(res < dis[i][j]) res = dis[i][j];
        }
    }
    
    if(flag == true) cout << res << endl;
    else cout << -1 << endl;

    return 0;
}