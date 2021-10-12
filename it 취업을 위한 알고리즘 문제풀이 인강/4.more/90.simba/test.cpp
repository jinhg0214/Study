#include <iostream>
#include <queue>

using namespace std;

// 심바의 상태 구조체
struct State{
    int x;
    int y;
    int dis;

    State(int a, int b, int c){
        x=a;
        y=b;
        dis=c;
    }

    bool operator<(const State &b)const{
        if(dis != b.dis) return dis > b.dis; // 1. 거리 우선
        if(x != b.x) return x > b.x;         // 2. 거리가 같다면 위쪽을 선택
        else return y > b.y;                 // 3. 거리가 같고, x가 같다면 왼쪽을 선택
    }
};

// 심바 구조체
struct Lion{
    int x;
    int y;
    int size;
    int ate;

    void sizeUp(){  
        ate = 0;
        size++;
    }
};

int map[26][26], ch[26][26];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int main(){
    freopen("G:\\Git\\Algorithm-C-\\4.more\\90.simba\\input.txt", "rt", stdin);

    priority_queue<State> pq;
    int n, m, res=0;
    Lion simba;

    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> map[i][j]; 
            if(map[i][j]==9){ //심바의 스타팅 위치 저장
                simba.x = i;
                simba.y = j;
                map[i][j]=0; // 빈 공간으로 설정함
            }
        }
    }

    pq.push(State(simba.x, simba.y, 0));

    simba.size = 2;
    simba.ate = 0;

    // BFS
    while(!pq.empty()){
        State tmp = pq.top();
        pq.pop();

        int x = tmp.x;
        int y = tmp.y;
        int dis = tmp.dis; 

        // 잡아먹을 수 있는 경우
        if(map[x][y] != 0 && map[x][y] < simba.size){
            simba.x = x;
            simba.y = y;
            simba.ate++; 

            // 렙업할수 있는지 확인
            if(simba.size == simba.ate){
                simba.sizeUp();
            }

            // 토끼 잔해 제거 및 체크 배열 초기화
            map[x][y]=0;
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    ch[i][j]=0;
                }
            }

            // 우선순위 큐 초기화
            while(!pq.empty()){pq.pop();}
            res = tmp.dis;
        }

        // 심바의 위치에서 상하좌우 확인 후 큐에 삽입
        for(int i=0; i<4; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];

            if(xx < 1 || xx > n || yy < 1 || y > n || // 경계 확인 
                map[xx][yy] > simba.size || // 심바의 크기와 토끼 크기 비교
                ch[xx][yy] > 0){ // 방문하지 않았는지 확인
                    continue;
            }

            pq.push(State(xx, yy, dis+1)); // 거리에 1을 추가 후, 우선순위 큐에 삽입 
            ch[xx][yy]=1; // 방문 체크
        }
    }
    cout << res << endl;

    return 0;
}