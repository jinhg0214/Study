#include <iostream>
#include <vector>

using namespace std;

int main(){
    freopen("G:\\Git\\Algorithm-C-\\6.DP\\10.napsack\\input.txt","rt",stdin);

    int n, m, w, v;

    cin >> n >> m;

    vector<int> dy(m+1, 0); // 가방 크기만큼 dy생성

    for(int i=0; i<n; i++){ // i 번째 보석 넣을수 있는지 확인
        cin >> w >> v;
        for(int j=w; j<=m; j++){
            dy[j] = max(dy[j], dy[j-w] + v);
        }
    }

    cout<<dy[m];

    return 0;
}