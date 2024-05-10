#include <iostream>
#include <cmath>
#include <string.h>

#define MAX 1000000

using namespace std;

bool grid[MAX + 1];

void check(int n) {
	// 4보다 큰 모든 짝수는 두 홀수 소수의 합으로 나타낼 수 있다
	// 6 ≤ n ≤ 1000000

	// 3부터 소수들끼리 더하기
	for (int i = 3; i <= MAX; i += 2) {
		if (grid[n - i] == false && grid[i] == false) {
			printf("%d = %d + %d\n", n, i, n - i);
			return;
		}
	}

	cout << "Goldbach's conjecture is wrong." << '\n';

	return;
}

void init() {
	memset(grid, 0, sizeof(grid));

	for (int i = 2; i <= MAX; i++) {
		if (grid[i] == true) {
			continue;
		}
		for (int j = i * 2; j <= MAX; j += i) {
			grid[j] = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	init();

	while (1) {
		int num;  cin >> num;
		if (num == 0) break;
		check(num);
	}

	return 0;
}