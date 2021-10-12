#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Edge{
    int vex;
    int dis;
    Edge(int a, int b){
        vex=a;
        dis=b;
    }
    // ������������ ����, ���� ���� ���� top���� �ö��
    bool operator<(const Edge &b)const{
        return dis > b.dis; 
    }
};

int main(){
    freopen("G:\\Git\\Algorithm-C-\\4.more\\80.Dijkstra\\input.txt", "rt", stdin);
    priority_queue<Edge> Q; 
    vector<pair<int, int> > graph[30];

    int i, n, m, a, b, c;

    cin >> n >> m;

    vector<int> dist(n+1, 2147000000); // dist �Ÿ� �迭�� INF ������ �ʱ�ȭ

    for(i=1; i<=m; i++){
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b,c)); // ����ġ ���� �׷����� ��������Ʈ�� �̿��Ͽ� ����
    }

    // Dijkstra �˰��� 
    Q.push(Edge(1,0));
    dist[1]=0; 

    while(!Q.empty()){
        int now = Q.top().vex;
        int cost = Q.top().dis;
        Q.pop();

        if(cost > dist[now]) continue; // ���� ����� �� ���ٸ� �Ʒ� ���� ��ŵ
        
        // ���� �۾�
        // ���� ���� ����� ������ ������ ����ġ�� Ȯ���Ͽ� ������
        for(i=0; i<graph[now].size(); i++){
            int next = graph[now][i].first; 
            int nextDis= cost + graph[now][i].second; // ���� ��� + ���� ���

            // ����� ����ġ ������ ����� ����ġ ���� ������ ������
            if(dist[next] > nextDis){
                dist[next] = nextDis; 
                Q.push(Edge(next, nextDis)); // �켱���� ť�� ���� ����
            }
        }
    }

    for(i=2; i<=n; i++){
        if(dist[i] != 2147000000) cout << i << " : " << dist[i] << endl;
        else cout << i << " : impossible" << endl;
    }
    
    return 0;

}