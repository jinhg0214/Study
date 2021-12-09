#include <iostream>

using namespace std;

int main() {
	char map[4][3];
	int a_y, a_x, b_y, b_x;

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 3; x++) {
			cin >> map[y][x];
			if (map[y][x] == 'A') {
				a_y = y; a_x = x;
			}
			if (map[y][x] == 'B') {
				b_y = y; b_x = x;
			}
		}
	}

	int res = abs(a_y - b_y) + abs(a_x - b_x);

	cout << res;

	return 0;
}