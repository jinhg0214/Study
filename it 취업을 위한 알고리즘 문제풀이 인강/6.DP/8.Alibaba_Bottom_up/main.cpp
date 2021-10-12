#include <iostream>
#include <algorithm>

/* 
최단 경로 cost 구하는 문제
dy[i][j] : (0,0)에서 (i,j)까지 도달하는데 드는 최소 비용을 저장

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

    // 가장자리 구하기
    for(int i=1; i<n; i++){
        dy[0][i] = dy[0][i-1] + arr[0][i];
        dy[i][0] = dy[i-1][0] + arr[i][0];
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            dy[i][j]=min(dy[i-1][j],dy[i][j-1]) + arr[i][j]; // 왼쪽과 위쪽의 dy값 중 작은 값 + arr[i][j]

        }
    }

    cout << dy[n-1][n-1];

    return 0;
}