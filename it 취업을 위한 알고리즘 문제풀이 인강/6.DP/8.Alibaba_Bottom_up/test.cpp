#include <iostream>

using namespace std;

int map[21][21];
int dy[21][21];  // ������ �� �ִ� �������� �ּҷ��� �����ϴ� dy

int main(){
    freopen("G:\\Git\\Algorithm-C-\\6.DP\\8.Alibaba_Bottom_up\\input.txt", "rt", stdin);

    int n;

    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> map[i][j];
        }
    }

    // Bottom-Up ��� �̿�
    dy[1][1]=map[1][1];

    // �׵θ� ó��
    for(int i=2; i<=n; i++){
        dy[1][i] = dy[1][i-1] + map[1][i]; // ���� dy + map[0][i]
        dy[i][1] = dy[i-1][1] + map[i][1]; // ���� dy + map[i][0]
    }

    // �� �� ������ DP ���
    for(int i=2; i<=n; i++){
        for(int j=2; j<=n; j++){
            dy[i][j] = min(dy[i-1][j], dy[i][j-1]) + map[i][j];// ���ʰ� ������ �ּҰ��� map[i][j] ���� ����
        }
    }

    cout << dy[n][n];

    return 0;
}