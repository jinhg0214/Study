#include <iostream>
#include <queue>

using namespace std;

// �ɹ��� ���� ����ü
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
        if(dis != b.dis) return dis > b.dis; // 1. �Ÿ� �켱
        if(x != b.x) return x > b.x;         // 2. �Ÿ��� ���ٸ� ������ ����
        else return y > b.y;                 // 3. �Ÿ��� ����, x�� ���ٸ� ������ ����
    }
};

// �ɹ� ����ü
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
            if(map[i][j]==9){ //�ɹ��� ��Ÿ�� ��ġ ����
                simba.x = i;
                simba.y = j;
                map[i][j]=0; // �� �������� ������
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

        // ��Ƹ��� �� �ִ� ���
        if(map[x][y] != 0 && map[x][y] < simba.size){
            simba.x = x;
            simba.y = y;
            simba.ate++; 

            // �����Ҽ� �ִ��� Ȯ��
            if(simba.size == simba.ate){
                simba.sizeUp();
            }

            // �䳢 ���� ���� �� üũ �迭 �ʱ�ȭ
            map[x][y]=0;
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    ch[i][j]=0;
                }
            }

            // �켱���� ť �ʱ�ȭ
            while(!pq.empty()){pq.pop();}
            res = tmp.dis;
        }

        // �ɹ��� ��ġ���� �����¿� Ȯ�� �� ť�� ����
        for(int i=0; i<4; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];

            if(xx < 1 || xx > n || yy < 1 || y > n || // ��� Ȯ�� 
                map[xx][yy] > simba.size || // �ɹ��� ũ��� �䳢 ũ�� ��
                ch[xx][yy] > 0){ // �湮���� �ʾҴ��� Ȯ��
                    continue;
            }

            pq.push(State(xx, yy, dis+1)); // �Ÿ��� 1�� �߰� ��, �켱���� ť�� ���� 
            ch[xx][yy]=1; // �湮 üũ
        }
    }
    cout << res << endl;

    return 0;
}