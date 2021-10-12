#include <bits/stdc++.h>

using namespace std;

/*
바로 친구면 1점
친구의 친구면 2점
...
최단거리를 가까움의 정도로 할 것!!
회원점수는 가장 큰값으로 설정

*/

int main(){
    ios_base::sync_with_stdio(false);
    freopen("G:\\Git\\Algorithm-C-\\6.DP\\14.chairman\\input.txt", "rt", stdin);

    int n, a, b, score;

    cin >> n;

    vector<vector<int> > dis(n+1, vector<int>(n+1, 100));
    vector<int> res(n+1);

    for(int i=1; i<=n; i++) dis[i][i]=0;

    while(true){
        cin >> a >> b;
        if(a == -1 && b == -1) break;
        dis[a][b]=1; // 무방향
        dis[b][a]=1;
    }

    // Floyd-warshall
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dis[i][j]=min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    score=100;

    // res에 i의 최대값을 바꿔주기
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            res[i] = max(res[i], dis[i][j]); 
        }
        score = min(res[i], score);
    }
    int cnt=0;
    for(int i=1; i<=n; i++){
        if(res[i] == score){ // 회장후보의점수
            cnt++;
        }
    }

    cout << score << " " << cnt << endl;

    for(int i=1; i<=n; i++){
        if(res[i] == score){
            cout << i << " ";
        }
    }

    return 0;
}