#include <iostream>
#include <vector>

using namespace std;

int dp[100001];

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	int N;
	cin >> N;
	vector<int> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
		dp[i] = -21e8;
	}
	
	dp[0] = v[0];

	for (int i = 1; i < N; i++) {
		dp[i] = max(dp[i - 1] + v[i], v[i]);
	}

	int max = -21e8;
	for (int i = 0; i < N; i++) {
		if (max < dp[i]) {
			max = dp[i];
		}
	}
	cout << max;

	return 0;
}

/*
	dp[0] = v[0];

	for (int i = 1; i < N; i++) {
		if (v[i] < 0)
			dp[i] = 0;
		else
			dp[i] = dp[i-1] + v[i];
	}

	음수 더한다고 무조건 0으로 처리하면 안됨.

	2 -1 99 와 같이 음수 끼고 가는게 더 큰 경우일수도 있음
*/