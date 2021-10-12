#include <stdio.h>
#include <queue>

/*
�ִܰŸ��� dis �迭�� ���
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

    // ���� �Է¹ޱ�
    for(int i=1; i<=7; i++){
        for(int j=1; j<=7; j++){
            scanf("%d", &map[i][j]);
        }
    }

    // BFS ����
    Q.push(Loc(1,1)); // (1.1) ���� ����
    map[1][1]=1; // map �迭�� �ٷ� �湮�ߴٰ� üũ�ع���

    while(!Q.empty()){
        Loc tmp = Q.front();
        Q.pop();

        // ���� ��ġ���� 4���� �̵��õ�
        for(int i=0; i<4; i++){
            int xx = tmp.x+dx[i];
            int yy = tmp.y+dy[i];

            if(map[xx][yy]==0 && // ��ǥ�� ����� ���� 0�̶�� �̵� ����
                xx >= 1 && xx <= 7 && // ���� ���� �ִ��� Ȯ��
                yy >= 1 && yy <=7 ){
                    Q.push(Loc(xx, yy));
                    map[xx][yy]=1; 
                    dis[xx][yy] = dis[tmp.x][tmp.y] +1; // �߿�! ���� ��ǥ +1 
                }
        }
    }
    printf("%d", dis[7][7]);

    return 0;

}