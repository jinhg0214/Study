#include <iostream>

using namespace std;

int N;
int arr[1001];
int dp[1001];

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		dp[i] = 1;
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] >= arr[j]) continue;

			dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	int res = 0;
	for (int i = 0; i < N; i++) {
		if (res < dp[i]) {
			res = dp[i];
		}
	}

	cout << res;

	return 0;
}