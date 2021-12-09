#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>

/*
Kruskal 알고리즘이 간선을 추가하는 방법이라면,
Prim 알고리즘은 정점을 추가하는 방법
임의의 정점을 선택 후, 그래프의 연결관계를 보면서 트리에 정점을 추가하며 확장함
정점이 N개가 되면 종료

Prim 알고리즘

1. 시작 노드 하나 선택. MST에 삽입.
2. MST에 그 노드가 있는지 확인 후, 그 노드와 연결된 간선들을 우선순위 큐에 넣음.
3. 최소 가중치 간선을 선택. 이를 MST에 넣음 
... 간선이 n-1개가 될때까지 2로 돌아가서 반복함
*/

using namespace std;

int ch[30]; // MST에 포함되어있는지 체크하는 배열

struct Edge{
    int e;
    int val;
    Edge(int a, int b){
        e=a;
        val=b;
    }
    bool operator<(const Edge &b)const{
        return val < b.val;
    }
};

int main(){
    freopen("G:\\Git\\Algorithm-C-\\4.more\\79.PrimMST\\input.txt", "rt", stdin);

    priority_queue<Edge> Q;
    vector<pair<int, int> > map[30]; // 인접리스트 이용

    int i, n, m, a, b, c, res=0;

    scanf("%d %d", &n, &m);
    
    // 인접리스트를 이용하여 무방향 그래프 저장
    for(i=1; i<=m; i++){
        scanf("%d %d %d", &a, &b, &c);
        map[a].push_back(make_pair(b,c));
        map[b].push_back(make_pair(a,c));
    }

    // Prim 알고리즘 시작
    Q.push(Edge(1,0)); // 1부터 시작

    while (!Q.empty()){
        Edge tmp = Q.top(); // 우선순위 큐의 top 값은 최소값임
        Q.pop();

        int v = tmp.e;
        int cost = tmp.val;

        if(ch[v]==0){ // MST에 아직 포함되지 않았다면
            res+= cost; // top의 가중치를 추가함
            ch[v]=1;

            // 이 노드와 연결된 간선들을 모두 우선순위 큐에 삽입한다
            for(i=0; i<map[v].size(); i++){
                Q.push(Edge(map[v][i].first, map[v][i].second));
            }
        }
    }
    printf("%d\n", res);

    return 0;
}