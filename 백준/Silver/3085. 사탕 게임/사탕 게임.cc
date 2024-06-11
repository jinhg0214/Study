#include <iostream>
#include <algorithm>

using namespace std;

char board[50][51];
int N;

// [y][x]와 [m][n]의 교환
void Swap(int y, int x, int m, int n) {

	char tmp;
	tmp = board[y][x];
	board[y][x] = board[m][n];
	board[m][n] = tmp;

}

// board에 연속되는 char가 존재하는지 확인하는 함수
int chk() {

	int ret = 0;

	// 가로로 확인
	for (int i = 0; i < N; i++) {
		int cnt = 1;
		for (int j = 0; j < N; j++) {
			if (board[i][j] == board[i][j + 1]) { // 옆에있는애랑 같으면 콤보 +1
				cnt++;
			}
			else {
				ret = max(ret, cnt);
				cnt = 1;
			}

		}
	}

	// 세로로 확인
	for (int j = 0; j < N; j++) {
		int cnt = 1;
		for (int i = 0; i < N; i++) {
			if (board[i][j] == board[i+1][j]) { // 아래있는애랑 같으면 콤보 +1
				cnt++;
			}
			else {
				ret = max(ret, cnt);
				cnt = 1;
			}

		}
	}

	return ret;

}


int main() {

	int ans = 0;
	
	cin >> N;

	// 입력받기
	for (int i = 0; i < N; i++) {
		scanf("%s", &board[i]);
	}

	// 교환 할 수 있는 경우의 수 확인
/*
					   [y-1][x]
					     ↑
			[y][x-1] ← [y][x] → [y][x+1]
						 ↓
					   [y+1][x]
*/
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			

			/* [y][x]의 위와 왼쪽 교환을 시행하지 않는 이유는
			[y-1][x], [x-1][y]를 시행하면서 이미 수행했기 때문에 생략
			*/
			// 오른쪽과 교환
			if (j + 1 < N) {

				Swap(i, j, i, j + 1);

				// 체크 수행
				ans = max(ans,chk());

				// 원상 복귀
				Swap(i, j, i, j + 1);
			}

			// 아래와 교환
			if (i + 1 < N) {
				
				Swap(i, j, i + 1, j);

				// 체크 수행
				ans = max(ans, chk());

				// 원상 복귀
				Swap(i, j, i + 1, j);
			}

		}
	}

	cout << ans;


}