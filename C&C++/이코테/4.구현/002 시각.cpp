#include <iostream>

using namespace std;

bool CheckThree(int h, int m, int s) {
	if (h % 10 == 3 || m / 10 == 3 || m % 10 == 3 || s / 10 == 3 || s % 10 == 3) {
		return true;
	}
	
	return false;
}

int main() {
	int N, cnt = 0;;
	cin >> N;

	for (int h = 0; h <= N; h++) {
		for (int m = 0; m < 60; m++) {
			for (int s = 0; s < 60; s++) {
				if (CheckThree(h, m, s)) {
					cnt++;
				}
			}
		}
	}

	cout << cnt;

	return 0;
}