#include <iostream>

using namespace std;

int map[21][21];
int dy[21][21];  // 도달할 수 있는 에너지의 최소량을 저장하는 dy

int main(){
    freopen("G:\\Git\\Algorithm-C-\\6.DP\\8.Alibaba_Bottom_up\\input.txt", "rt", stdin);

    int n;

    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> map[i][j];
        }
    }

    // Bottom-Up 방식 이용
    dy[1][1]=map[1][1];

    // 테두리 처리
    for(int i=2; i<=n; i++){
        dy[1][i] = dy[1][i-1] + map[1][i]; // 왼쪽 dy + map[0][i]
        dy[i][1] = dy[i-1][1] + map[i][1]; // 위쪽 dy + map[i][0]
    }

    // 그 외 나머지 DP 계산
    for(int i=2; i<=n; i++){
        for(int j=2; j<=n; j++){
            dy[i][j] = min(dy[i-1][j], dy[i][j-1]) + map[i][j];// 왼쪽과 위쪽중 최소값을 map[i][j] 값과 더함
        }
    }

    cout << dy[n][n];

    return 0;
}