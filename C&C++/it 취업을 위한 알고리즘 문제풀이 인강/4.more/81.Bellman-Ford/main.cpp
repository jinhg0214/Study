#include <stdio.h>
#include <vector>

using namespace std;

/* 열은 간선 선택 개수, 행은 노드까지 가는데 드는 비용
    1   2   3   4   5   
    0   INF INF INF INF
1   0   5   4   INF INF (간선 한번 이용시)
2   0   5   2   9   18  (두번) 
3   0   5   2   7   16
4   0   5   2   7   14

*/

int dist[101];

struct Edge{
    int s;
    int e;
    int val;
    Edge(int a, int b, int c){
        s=a;
        e=b;
        val=c;
    }
};

int main(){
    freopen("G:\\Git\\Algorithm-C-\\4.more\\81.Bellman-Ford\\input.txt", "rt", stdin);
    vector<Edge> Ed;    

    int n, m, i, j, a, b, c, s, e;
    scanf("%d %d", &n, &m);

    // 벡터에 간선 정보를 저장
    for(i=1; i<=m; i++){
        scanf("%d %d %d", &a, &b, &c);
        Ed.push_back(Edge(a,b,c));
    }

    // dist 배열 INF로 초기화
    for(i=1; i<=n; i++){
        dist[i] = 2147000000;
    }

    // 출발 도착 노드 설정
    scanf("%d %d", &s, &e);

    // Bellman-ford 알고리즘 시작
    dist[s]=0; // 출발 정점

    // i : i번만에 도달할 수 있는 노드들
    for(i=1; i<n; i++){
        for(j=0;j<Ed.size(); j++){ // 그 노드와 연결된 간선 확인
            int u=Ed[j].s; // u : 출발
            int v=Ed[j].e; // v : 도착
            int w=Ed[j].val;

            // 출발 + 가중치 와 기존 v를 비교 
            if(dist[u]!=2147000000 && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;    // 값을 갱신
            }
        }
    }

    // 음의 사이클이 존재하는지 확인
    for(j=0; j<Ed.size(); j++){
        int u=Ed[j].s; // u : 출발
        int v=Ed[j].e; // v : 도착
        int w=Ed[j].val;

        if(dist[u]!=2147000000 && dist[u] + w < dist[v]){
            printf("-1\n");
            return -1;
        } 
    }
    printf("%d\n", dist[e]);

    return 0;
}