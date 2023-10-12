#include <iostream>

using namespace std;

int cnt = 0;
int T, N;

void Permutation(int level, int sum) {
	if (sum > N) return;
	if (sum == N) {
		cnt++;
		return;
	}

	for (int x = 1; x <= 3; x++) {
		Permutation(level + 1, sum + x);
	}
}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> T;
	while (T--) {
		cnt = 0;
		cin >> N;
		Permutation(0, 0);
		cout << cnt << '\n';
	}

	return 0;
}