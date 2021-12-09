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
                Q.push(Loc(i,j)); // ������ �丶���� ��ǥ�� ����
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

            // ��� ó��
            if(xx < 1 || xx > n || yy < 1 || yy > m) continue;

            // ���ڸ� �丶�䰡 �����Ǿ����� Ȯ��
            if(map[xx][yy] == 0){
                Q.push(Loc(xx,yy));

                map[xx][yy] = 1; // �����Ȱ����� ó��
                dis[xx][yy] = dis[tmp.x][tmp.y] + 1; // ���� �Ÿ� ����
            }
        }
    }
    bool flag = true;
    int res = -2147000000; // �ִ� ������ ���� ����

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(map[i][j]==0) flag = false; // �̼��� �丶�䰡 �ִٸ� false��
            if(res < dis[i][j]) res = dis[i][j];
        }
    }
    
    if(flag == true) cout << res << endl;
    else cout << -1 << endl;

    return 0;
}