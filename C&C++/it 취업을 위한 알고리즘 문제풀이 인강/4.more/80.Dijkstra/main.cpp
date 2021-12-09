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
    // 내림차순으로 정렬, 가장 작은 값이 top으로 올라옴
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

    vector<int> dist(n+1, 2147000000); // dist 거리 배열을 INF 값으로 초기화

    for(i=1; i<=m; i++){
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b,c)); // 가중치 방향 그래프를 인접리스트를 이용하여 생성
    }

    // Dijkstra 알고리즘 
    Q.push(Edge(1,0));
    dist[1]=0; 

    while(!Q.empty()){
        int now = Q.top().vex;
        int cost = Q.top().dis;
        Q.pop();

        if(cost > dist[now]) continue; // 이전 비용이 더 낮다면 아래 동작 스킵
        
        // 갱신 작업
        // 현재 노드와 연결된 노드들의 간선의 가중치를 확인하여 갱신함
        for(i=0; i<graph[now].size(); i++){
            int next = graph[now][i].first; 
            int nextDis= cost + graph[now][i].second; // 현재 비용 + 다음 비용

            // 저장된 가중치 값보다 계산한 가중치 값이 작으면 갱신함
            if(dist[next] > nextDis){
                dist[next] = nextDis; 
                Q.push(Edge(next, nextDis)); // 우선순위 큐에 값을 삽입
            }
        }
    }

    for(i=2; i<=n; i++){
        if(dist[i] != 2147000000) cout << i << " : " << dist[i] << endl;
        else cout << i << " : impossible" << endl;
    }
    
    return 0;

}