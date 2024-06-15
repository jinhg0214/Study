#include <iostream>
#include <numeric>

using namespace std;

int solution(int M, int N, int x, int y) {
	int result = -1;
	int max_i = lcm(M, N); // 멸망해
	for (int i = x; i <= max_i; i += M) {
		int ny = i % N;
		if (ny == 0) {
			ny = N;
		}
		if (ny == y) {
			result = i;
			break;
		}
	}

	return result;
}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);

	int T; cin >> T;
	while (T--) {
		int M, N, x, y;
		cin >> M >> N >> x >> y;

		cout << solution(M, N, x, y) << '\n';
	}

	return 0;
}
