// 같은 수를 두번 이상 연속해서 사용하면 안된다
// n을 1, 2, 3의 합으로 나타내는 방법의 수를 1,000,000,009로 나눈 나머지를 출력

#include <bits/stdc++.h>

using namespace std;

int T, N;
unsigned long long int dp[100001][4]; // 2차원 DP. [N][마지막으로 온 숫자]

void init() {
	dp[1][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1;

	// dp[i] = dp[i-3]+ dp[i-2] + dp[i-1]

	for(int i=4; i<= 100000; i++){
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % 1000000009;
		dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % 1000000009;
		dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % 1000000009;
	}
}

int main() {
	init();

	cin >> T;
	while (T--) {
		cin >> N;
		cout << (dp[N][1] + dp[N][2] + dp[N][3]) % 1000000009 << '\n';
	}

	return 0;
}