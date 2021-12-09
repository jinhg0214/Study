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

    // �ּҰ��� ���ؾ��ϹǷ� INF���� �ʱ�ȭ
    vector<int> dy(m+1, 1000);
    dy[0] = 0;

    //napsack �˰���
    for(int i=0; i<n; i++){
        for(int j=coin[i]; j<=m; j++){
            dy[j] = min(dy[j], dy[j-coin[i]]+1); // napsack�� dy[j-w]+v�� ������
        }
    }

    cout << dy[m];

    return 0;
}