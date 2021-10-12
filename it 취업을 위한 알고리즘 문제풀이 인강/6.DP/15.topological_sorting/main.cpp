/*
진입 차수를 저장하는 배열
        1   2   3   4   5   6
degree  0   1   2   2   1   0     

0부터 순서대로 큐에 삽입 
큐에서 꺼내면서, 그 수가 만드는 진입차수를 1 감소시켜줌
ex) 6을 꺼내면서 2를 1 감소시킴-> 다음 큐에 2가 들어가게됨

queue 1 6 2 5 4 3   

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    freopen("G:\\Git\\Algorithm-C-\\6.DP\\15.topological_sorting\\input.txt", "rt", stdin);

    int n, m, a, b, score;

    cin >> n >> m;

    vector<vector<int> > graph(n+1, vector<int>(n+1, 0));
    vector<int> degree(n+1);
    queue<int> Q;

    for(int i=0; i<m; i++){
        cin >> a >> b;
        graph[a][b]=1; // 단방향
        degree[b]++; // 진입차수 1 증가
    }

    // 진입차수가 0인 노드 먼저 처리
    for(int i=1; i<=n; i++){
        if(degree[i]==0) Q.push(i); 
    }

    while(!Q.empty()){
        int now = Q.front();
        Q.pop();

        cout << now << " ";

        for(int i=1; i<=n; i++){
            if(graph[now][i] == 1){  //i와 연결된 노드의 진입차수 1 감소
                degree[i]--;
                if(degree[i] == 0) Q.push(i); //i가 0이 되면 큐에 삽입
            }
        }
    }

    return 0;
}