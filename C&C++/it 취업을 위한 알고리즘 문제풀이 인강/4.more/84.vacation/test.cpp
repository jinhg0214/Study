#include <iostream>
#include <vector>

using namespace std;

int a[16], n, res = 0;
int T[16], P[16];

void DFS(int L, int sum){
    if(L == n+1){ // n+1���� ����(������������ ���� �� ����)
        if(sum > res){
            res = sum;
        }
    }
    else{
        if(L+T[L] <= n+1){
            DFS(L+T[L], sum + P[L]); // T[L]�� �����ϴ� ���
        }
        DFS(L+1, sum); // �������� �ʴ� ���
    }
}

int main(){
    freopen("G:\\Git\\Algorithm-C-\\4.more\\84.vacation\\input.txt", "rt", stdin);
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> T[i] >> P[i];
    }

    DFS(1,0);
    cout << res << endl;

    return 0;
}