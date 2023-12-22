#include <iostream>
#include <string.h>

using namespace std;

int T, n, m;
int cnt;

long long int dp[11][2010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> T;
	while (T--) {
		cnt = 0;
		cin >> n >> m;
		memset(dp, 0, sizeof(dp));

		// 
		for (int j = 1; j <= m; j++) {
			dp[1][j] = j;
		}

		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j / 2];
			}
		}

		cout << dp[n][m] << endl;
	}
	return 0;
}
