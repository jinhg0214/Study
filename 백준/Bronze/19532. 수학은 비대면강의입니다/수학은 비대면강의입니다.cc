#include <iostream>

using namespace std;

int main() {
	int a, b, c, d, e, f;
	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

	for (int x = -999; x < 1000; x++) {
		for (int y = -999; y < 1000; y++) {
			if ((a * x + b * y == c) && (d * x + e * y == f)) {
				printf("%d %d", x, y);
				return 0;
			}
		}
	}
	// y를 x에 대해서 정리하여 푸는 방법도 있지마
	// 시간복잡도가 2000 * 2000 = 4, 000, 000 정도로 1초 내에 계산 가능하므로
	// 완전탐색으로 풀이
	return 0;
}