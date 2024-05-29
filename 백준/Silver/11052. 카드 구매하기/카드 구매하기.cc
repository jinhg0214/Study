#include <iostream>
#include <cmath>
#include <algorithm> // min, max 3개 인자 비교에 사용

#define MAX 10001

using namespace std;

int N;
int p[MAX];
int dp[MAX];

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> p[i];
	}

	dp[1] = p[1];
	dp[2] = max(2 * p[1], p[2]);
	dp[3] = max({ 3 * p[1], p[1] + p[2], p[3] });

	for (int i = 4; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + p[j]);
		}
	}

	cout << dp[N];

	return 0;
}
