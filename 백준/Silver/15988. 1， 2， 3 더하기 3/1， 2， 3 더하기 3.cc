#include <iostream>

#define MOD 1000000009

using namespace std;

int dp[1000001]; // N을 만드는 방법의 수

void init() {
	dp[1] = 1; // 1을 만드는 방법의 수 1개 (1)
	dp[2] = 2; // 2를 만드는 방법의 수 2개 (1+1, 2)
	dp[3] = 4; // 3을 만드는 방법의 수 3개 (1+1+1, 1+2, 2+1, 3)

	for (int i = 4; i <= 1000000; i++) {
		dp[i] = ((dp[i - 1] + dp[i - 2]) % MOD + dp[i - 3]) % MOD;
	}
}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	init();

	int T; cin >> T;
	while (T--) {
		int N;
		cin >> N;

		cout << dp[N] << '\n';
	}

	return 0;
}

