#include <iostream>
#include <vector>

/*
dy[j] : 가방에 j무게 까지 담을 수 있을 때, 보석의 최대 가치?
    0   1   2   3   4   5   6   7   8   9   10  11
dy  0   0   0   0   0   0   0   0   0   0   0   0
dy  0   0   0   0   0   12  12  12  12  12  24  24  // w5 v12 입력 dy[j-w] + v
dy  0   0   0   8   8   12  16  16  20  24  24  28   // w3 v8 입력, dy[5]에서 충돌! max(dy[2]+v,dy[5])
dy  0   0   0   8   8   12  16  16  20  24  24  28   // w6 v14 ...


*/

using namespace std;

int main(){
    freopen("G:\\Git\\Algorithm-C-\\6.DP\\10.napsack\\input.txt","rt",stdin);

    int n, m ,w, v;

    cin >> n >> m;

    vector<int> dy(m+1, 0);

    for(int i=0; i<n; i++){
        cin >> w >> v;
        for(int j=w; j<=m; j++){
            // dy를 갱신
            dy[j] = max(dy[j], dy[j-w] + v);
        }
    }

    cout << dy[m];

    return 0;
}
