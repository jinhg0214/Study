/*
플로이드 워샬 알고리즘.
모든 정점에서의 모든 다른 정점으로까지의 최단거리를 구하는 알고리즘

d[i][j] : i노드 -> j노드로 가는데 드는 최소 비용을 저장하는 2차원 배열
 
dis 1   2   3   4   5
1   0   6   3   M   M
2   M   0   M   1   13
3   M   2   0   5   M
4   M   3   M   0   7
5   M   M   M   M   0

1. 인접 행렬을 초기화(한번에 도달 할 수 있는곳) 
2. 인접하지 않은 곳은 INF 로 초기화
3. (dis[i][j], dis[i][k] + dis[k][j]) 비교(k노드에 방문하는 비용과 비교)

K=3, dis[5][4] = dis[5][3]  + dis[3][4] + dis[4][5]
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    freopen("G:\\Git\\Algorithm-C-\\6.DP\\13.Floyd_Warshall\\input.txt", "rt", stdin);

    int n, m, a,b,c;

    cin >> n >> m;

    vector<vector<int> > dis(n+1, vector<int>(n+1, 5000)); // INF로 초기화된 2차원 벡터

    for(int i=1; i<=n; i++) dis[i][i] = 0; // 자기 자신과의 거리는 0

    // 한번에 도달 할 수 있는 곳을 초기화
    for(int i=1; i<=m; i++){
        cin >> a >> b >> c;
        dis[a][b] = c; 
    }

    // DP
    for(int k=1; k<=n; k++){ 
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){ // i -> k -> j
                if(dis[i][j] > dis[i][k] + dis[k][j]){
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(dis[i][j]== 5000){
                cout << "M ";
            }
            else cout << dis[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}