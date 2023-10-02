#include <iostream>

using namespace std;

int t[1001] = { 0 };

// t의 세 숫자를 더한 값이 num과 같은지 체크
bool check(int num) {
	for (int i = 1; i <= 50; i++) {
		for (int j = 1; j <= 50; j++) {
			for (int k = 1; k <= 50; k++) {
				if (t[i] + t[j] + t[k] == num) {
					return true;
				}
			}
		}
	}
	return false;
}

int main() {
	// 1. 누적합을 1000까지 먼저 구한다
	for (int i = 1; i <= 1000; i++) {
		t[i] = t[i - 1] + i;
	}


	int N, K;

	cin >> N;

	while (N--) {
		cin >> K; // (3 <= K <= 1000)

		// K가 3개의 삼각수의 합으로 표현할 수 있는지 체크
		cout << check(K) << endl;
	}


	return 0;
}