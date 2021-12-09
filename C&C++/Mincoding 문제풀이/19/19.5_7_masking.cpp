#include <iostream>

using namespace std;

int main() {
	int map[3][3] = {
		3,5,1,
		3,8,1,
		1,1,5,
	};

	int bitarray[2][2];

	for (int y = 0; y < 2; y++) {
		for (int x = 0; x < 2; x++) {
			cin >> bitarray[y][x];
		}
	}

	int max = -21e8;
	int max_y = 0, max_x = 0;

	for (int y = 0; y < 2; y++) {
		for (int x = 0; x < 2; x++) {
			int sum = 0;
			
			// bitarray masking

			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 2; j++) {
					int dy = y + i;
					int dx = x + j;

					if (dy < 0 || dx < 0 || dy > 2 || dx > 2) continue;

					if (bitarray[i][j] == 1) {
						sum += map[dy][dx];
					}

				}
			}

			if (sum > max) {
				max = sum;
				max_y = y;
				max_x = x;
			}

		}
	}

	cout << "(" << max_y << "," << max_x << ")";

	return 0;
}