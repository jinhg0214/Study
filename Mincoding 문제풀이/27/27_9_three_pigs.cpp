#include <iostream>

using namespace std;

int directY[8] = { 0, -1, 0, 1 ,-1, -1, 1, 1};
int directX[8] = { -1, 0, 1, 0 , -1, 1, 1, -1};

int main() {
	int map[4][4] = { 0 }; //0: 빈땅, 1: 집, 2: 벽

	int y, x;

	for (int i = 0; i < 3; i++) {
		cin >> y >> x;
		map[y][x] = 1;

		for (int j = 0; j < 8; j++) {
			int dy = y + directY[j];
			int dx = x + directX[j];

			if (dy < 0 || dx < 0 || dy > 3|| dx > 3) continue;
			if (map[dy][dx] == 1 || map[dy][dx] == 2) continue;

			map[dy][dx] = 2;
		}
	}

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (map[y][x] == 0) { cout << "_"; }
			else if (map[y][x] == 1) { cout << "#"; }
			else if (map[y][x] == 2) { cout << "@"; }
		}
		cout << endl;
	}


	return 0;
}