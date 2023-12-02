#include <iostream>

using namespace std;

int min_level = 21e8;

void run(int level, int n) {
	if (n < 1) return; // 바닥조건 1 : n이 1보다 작아진경우 더이상 안봄
	if (level > min_level) return; // 바닥조건 2 : 이미 구한 최소값보다 더 커진 경우 더이상 안봄
	if(n == 1){ // 바닥조건 3 : n이 1인 경우, 최소값을 갱신함
		if (level < min_level) min_level = level;
		return;
	}

	if (n % 3 == 0) {
		run(level + 1, n / 3);
	}

	if (n % 2 == 0) {
		run(level + 1, n / 2);
	}

	run(level + 1, n - 1);
}

int main() {
	int X;
	cin >> X;

	run(0, X);

	cout << min_level;
}