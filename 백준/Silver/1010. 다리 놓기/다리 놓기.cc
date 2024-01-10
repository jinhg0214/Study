#include <iostream>

using namespace std;

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	int T, N, M;
	cin >> T;

	while (T--) {
		cin >> N >> M;

		if (N == 0 || M == 0) {
			cout << 0 << endl;
			continue;
		}

		unsigned long long int result = 1;
		int r = 1;

		for (int i = M; i >= M - N + 1; i--) {
			result *= i;
			result /= r;
			r++;
		}

		
		cout << result << endl;
	}

	return 0;
}