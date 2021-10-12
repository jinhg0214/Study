#include <iostream>
#include <vector>

using namespace std;

int main(){
    freopen("G:\\Git\\Algorithm-C-\\6.DP\\10.napsack\\input.txt","rt",stdin);

    int n, m, w, v;

    cin >> n >> m;

    vector<int> dy(m+1, 0); // ���� ũ�⸸ŭ dy����

    for(int i=0; i<n; i++){ // i ��° ���� ������ �ִ��� Ȯ��
        cin >> w >> v;
        for(int j=w; j<=m; j++){
            dy[j] = max(dy[j], dy[j-w] + v);
        }
    }

    cout<<dy[m];

    return 0;
}