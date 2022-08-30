#include <iostream>

using namespace std;

int M, N;
int result[101];

int main() {
	// freopen_s(new FILE*, "sample_input.txt", "r", stdin);
	cin >> M >> N;

	int min = 1;
	for (int i = 1; i <= 100; i++) {
		if (i * i >= M) {
			min = i;
			break;
		}
	}

	if (min * min > N) {
		cout << -1;
		return 0;
	}

	int sum = 0;
	for (int i = min; i*i <= N; i++) {
		sum += i * i;
	}

	cout << sum << endl << min * min;

	return 0;
}