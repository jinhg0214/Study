#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    freopen("G:\\Git\\Algorithm-C-\\6.DP\\11.coin_exchange\\input.txt", "rt", stdin);

    int n, m;
    
    cin >> n;

    vector<int> coin(n);

    for(int i=0; i<n; i++) cin >> coin[i];

    cin >> m;

    // 최소값을 구해야하므로 INF으로 초기화
    vector<int> dy(m+1, 1000);
    dy[0] = 0;

    //napsack 알고리즘
    for(int i=0; i<n; i++){
        for(int j=coin[i]; j<=m; j++){
            dy[j] = min(dy[j], dy[j-coin[i]]+1); // napsack의 dy[j-w]+v와 유사함
        }
    }

    cout << dy[m];

    return 0;
}