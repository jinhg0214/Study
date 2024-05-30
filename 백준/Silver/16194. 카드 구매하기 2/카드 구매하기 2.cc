#include <bits/stdc++.h>

using namespace std;

int N;
int p[1001];
int dp[1001];

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> p[i];
	}

	for (int i = 1; i <= N; i++) {
		dp[i] = 21e8;
	}

	dp[1] = p[1];
	dp[2] = min(2 * p[1], p[2]);

	for (int i = 3; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = min(dp[i], dp[i-j] + p[j]);
		}
	}

	cout << dp[N];

	return 0;
}