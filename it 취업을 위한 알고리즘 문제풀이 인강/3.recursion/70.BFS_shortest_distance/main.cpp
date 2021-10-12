#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int ch[30]={0}, dis[30]={0};

int main(){
    freopen("G:\\Git\\Algorithm-C-\\3.recursion\\70.BFS_shortest_distance\\input.txt", "rt", stdin);

    int n, m, i, start, end, x;
    vector<int> map[30];
    queue<int> q;

    scanf("%d %d", &n, &m);
    for(i=1; i<=m; i++){
        scanf("%d %d", &start, &end);
        map[start].push_back(end);
    }

    // BFS
    q.push(1);
    ch[1]=1; // 1�� ��带 ���������

    while(!q.empty()){
        x=q.front();    // x�� ť�� �� ���� ��
        q.pop();        // �� ���� ���� ����

        for(i=0; i<map[x].size(); i++){
            if(ch[ map[x][i] ]==0){
                ch[ map[x][i] ]=1;
                q.push( map[x][i] );
                dis[map[x][i]]=dis[x]+1; // x�� ���� i�� �̵������Ƿ�, �ּҰ������� +1�� ����
            }
        }
    }

    for(i=2; i<=n; i++){
        printf("%d : %d\n", i, dis[i]);
    }

    return 0;
}