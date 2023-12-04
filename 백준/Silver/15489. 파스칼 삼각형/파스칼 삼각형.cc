#include <iostream>

using namespace std;

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	int R, C, W;
	cin >> R >> C >> W;

	int t[50][50] = { 0 };

	// 1. 30줄까지 파스칼 삼각형 만들기
	// R[N] = [ 1, R[N-1][0] + R[N-1][1], R[N-1][1]+R[N-1][2], ... , R[N-1][N-2][N-1][N-1], 1]
	// R[N][x] = R[N-1][x-1] + R[N-1][x] 로 표현할 수 있음
	t[0][0] = 1;
	t[1][0] = 1;
	t[1][1] = 1;

	for (int i = 2; i < 30; i++) {
		for (int j = 0; j < i + 1; j++) {
			if (j == 0 || j == i)
				t[i][j] = 1;
			else
				t[i][j] = t[i - 1][j - 1] + t[i - 1][j];
		}
	}
	
	// 2. 첫째 줄에 R번째 줄, C번째 수를 위 꼭짓점으로 하는 
	// 한 변이 포함하는 수의 개수가 W인 정삼각형과 그 내부에 있는 수들의 합을 출력 
	int sum = 0;
	
	int idx = 0;
	for (int i = R - 1; i < R - 1 + W; i++) { // R번째 줄
		for (int j = C - 1; j <= C - 1 + idx; j++) { // C번째 수 

			sum += t[i][j];
		}
		idx++;
	}
	cout << sum;

	return 0;
}