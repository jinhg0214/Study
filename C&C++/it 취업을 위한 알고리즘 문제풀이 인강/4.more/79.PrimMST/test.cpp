#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int ch[30]; // MST에 포함되어있는지 체크하는 배열

struct Edge{ // 노드
    int e; // 연결된 노드
    int val; // 노드와 연결된 간선의 가중치
    Edge(int a, int b){
        e = a;
        val = b;
    }
    bool operator<(const Edge& b)const{
        return this->val < b.val;
    }
};

int main(){
    freopen("G:\\Git\\Algorithm-C-\\4.more\\79.PrimMST\\input.txt", "rt", stdin);

    int n, m, i, start, end, weight, res=0;
    // vector<pair<int,int> > map[30];
    priority_queue<Edge> Q;

    cin >> n >> m;

    /*
    for(i=1; i<=m; i++){
        cin >> start >> end >> weight;

        // 무방향 간선
        map[start].push_back(make_pair(end,weight));
        map[end].push_back(make_pair(start,weight));
    }*/

    vector<Edge> map[30]; // 벡터

    for(i=1; i<=m; i++){
        cin >> start >> end >> weight;

        // 무방향 간선
        map[start].push_back(Edge(end,weight));
        map[end].push_back(Edge(start,weight));
    }


    // Prim 알고리즘

    Q.push(Edge(1,0)); // 노드 1부터 시작, 자기 자신과의 가중치는 1
    
    while(!Q.empty()){
        Edge tmp = Q.top();
        Q.pop();

        int v = tmp.e;
        int cost = tmp.val;

        if(ch[v]==0){

            res += cost;
            ch[v]=1;

            // 현재 노드와 연결된 노드들을 큐에 추가
            for(i=0; i<map[v].size(); i++){
                Q.push(Edge(map[v][i].e, map[v][i].val));
            }
        }
    }
    cout << res << endl;

    return 0;
}