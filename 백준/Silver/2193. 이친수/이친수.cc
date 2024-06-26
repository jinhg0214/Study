#include <iostream>

using namespace std;

int N;
long long int dp[91][2];

int main() {
	cin >> N;

	dp[1][1] = 1;
	dp[2][0] = 1;
	
	for (int i = 3; i <= N; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}

	cout << dp[N][0] + dp[N][1];

	return 0;
}