#include <iostream>

using namespace std;

int dp[11];

int main() {

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i <= 10; i++) {
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	}

	int T; cin >> T;
	while (T--) {
		int n;
		cin >> n;
		cout << dp[n] << '\n';
	}
	
	return 0;
}