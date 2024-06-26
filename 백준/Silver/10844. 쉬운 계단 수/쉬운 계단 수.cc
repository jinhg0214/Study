#include <iostream>

#define MOD 1000000000

using namespace std;

int dp[101][10];

int main() {
	int N; cin >> N;

	// 1의 자리수는 모두 1
	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) {
				dp[i][0] = dp[i - 1][1];
			}
			else if (j == 9) {
				dp[i][9] = dp[i - 1][8];
			}
			else {
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
			}
		}
	}
	int res = 0;
	for (int i = 0; i <= 9; i++) {
		res = (res + dp[N][i]) % MOD;
	}
	cout << res;

	return 0;
}