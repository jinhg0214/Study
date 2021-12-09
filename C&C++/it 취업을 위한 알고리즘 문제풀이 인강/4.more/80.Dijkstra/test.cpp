#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Edge{
    int v;
    int dis;
    Edge(int a, int b){
        v = a;
        dis = b;
    }
    bool operator<(const Edge &b)const{
        return dis < b.dis;
    }
};

int main(){
    freopen("G:\\Git\\Algorithm-C-\\4.more\\80.Dijkstra\\input.txt", "rt", stdin);

    int n, m, i, a, b, c;
    vector<Edge> map[30];
    priority_queue<Edge> Q;

    cin >> n >> m;

    vector<int> d(n+1,2147000000);

    // �ܹ��� ������ ���� �׷��� 
    for(i=1; i<=m; i++){
        cin >> a >> b >> c;
        map[a].push_back(Edge(b,c));
    }

    // Dijjkstra
    Q.push(Edge(1,0));
    d[1]=0;

    while(!Q.empty()){
        int now = Q.top().v; // ���� ���
        int cost = Q.top().dis; // ����ġ
        Q.pop();

        if(cost > d[now]) continue;

        // now���� ����� ������ ����ġ�� ��
        for(i=0; i<map[now].size(); i++){
            int next = map[now][i].v;
            int nextDis = cost + map[now][i].dis;

            if(d[next] > nextDis){ // ���� ���� cost�� �ִٸ� d[next]�� ����� ���� �ٲ�
                d[next] = nextDis;
                Q.push(Edge(next, nextDis));
            }

        }

    }

    for(i=2; i<=n; i++){
        if(d[i] != 2147000000) cout << i << " : " << d[i] << endl;
        else cout << i << " : impossible" << endl;
    }

    return 0;
}