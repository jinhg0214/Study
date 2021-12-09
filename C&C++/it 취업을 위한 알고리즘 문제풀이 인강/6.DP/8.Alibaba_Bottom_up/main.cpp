#include <iostream>
#include <algorithm>

/* 
�ִ� ��� cost ���ϴ� ����
dy[i][j] : (0,0)���� (i,j)���� �����ϴµ� ��� �ּ� ����� ����

*/
using namespace std;

int arr[21][21], dy[21][21];

int main(){
    freopen("G:\\Git\\Algorithm-C-\\6.DP\\8.Alibaba_Bottom_up\\input.txt", "rt", stdin);

    int n;

    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    // DP
    dy[0][0] = arr[0][0];

    // �����ڸ� ���ϱ�
    for(int i=1; i<n; i++){
        dy[0][i] = dy[0][i-1] + arr[0][i];
        dy[i][0] = dy[i-1][0] + arr[i][0];
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            dy[i][j]=min(dy[i-1][j],dy[i][j-1]) + arr[i][j]; // ���ʰ� ������ dy�� �� ���� �� + arr[i][j]

        }
    }

    cout << dy[n-1][n-1];

    return 0;
}