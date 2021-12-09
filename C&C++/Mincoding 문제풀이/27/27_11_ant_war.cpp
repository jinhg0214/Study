#include <iostream>

using namespace std;

int main() {
	int map[4][4];

	int directY[4] = { 0,-1,0,1 };
	int directX[4] = { -1,0,1,0 };

	bool flag = false;

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			cin >> map[y][x];
		}
	}

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (map[y][x] == 1) {
				for (int i = 0; i < 4; i++) {
					int dy = y + directY[i];
					int dx = x + directX[i];

					if (dy < 0 || dx < 0 || dy > 3 || dx > 3) continue;
					if (map[dy][dx] == 1) {
						flag = true;
						break;
					}
				}
			}
		}
	}
	

	if (flag == true) {
		cout << "위험한 상태";
	}
	else {
		cout << "안전한 상태";
	}

}