#include <stdio.h>
#include <queue>

/* BFS �̿�
1. 2���� �迭 map�� ���� ������ �о���δ�
2. map[n][m]1�� ������ ť�� ��ǥ�� �ְ�, �����¿�, �밢���� 1�� �ִ��� Ȯ��
3. �湮�� ���� 0���� �ٲ۴�(�ٽ� �湮���� �ʵ���)
4. ��� ������ 0�̶��, ť�� push�� ���� �����Ƿ� ��, �̶� ���� ������ �ϳ� �߰���.
5. map[n+1][m+1]�� �̵� �� �ݺ�... map[N][N]���� Ž���غ��� 
*/
using namespace std;

int n, map[30][30], cnt=0;
int dx[8]={0, 1, 1, 1, 0, -1, -1, -1}; // 12, 1:30, 3, 4:30, 6, 7:30, 9, 10:30
int dy[8]={-1, -1, 0, 1, 1, 1, 0, -1};

// ��ǥ ����ü
struct Loc{
    int x;
    int y;
    Loc(int a, int b){
        x=a;
        y=b;
    }
};

queue<Loc> Q; // ��ǥ�� �����ϴ� ť

int main(){
    freopen("G:\\Git\\Algorithm-C-\\4.more\\87.island\\input.txt", "rt", stdin);
    int i, j;

    scanf("%d", &n);

    // �ʿ� ������ ����
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            scanf("%d", &map[i][j]);
        }
    }

    // BFS 
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            if(map[i][j]==1){ // ���� ��ǥ�� ���̶��
                Q.push(Loc(i,j)); // ť�� ���� ��ǥ ����
                map[i][j]=0; // �ٽ� �湮���� �ʵ��� 0���� �ٲ�

                while(!Q.empty()){
                    Loc tmp = Q.front();
                    Q.pop();

                    // ť�� ����� ��ǥ�� ����� ���� ã��
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