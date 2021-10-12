#include <iostream>

using namespace std;

int main() {
	int map[4][5];

	int leftBorder = 5;
	int rightBorder = -1;
	int topBorder = 5;
	int bottomBorder = -1;

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 5; x++) {
			cin >> map[y][x];
			if (map[y][x] != 0) {
				if (x < leftBorder) { leftBorder = x; }
				if (rightBorder < x) { rightBorder = x; }
				if (y < topBorder) { topBorder = y; }
				if (bottomBorder < y) { bottomBorder= y; }
			}
		}
	}

	cout << "(" << topBorder << "," << leftBorder << ")" << endl;
	cout << "(" << bottomBorder << "," << rightBorder<< ")" << endl;

	// 사각 프레임의 시작점과 끝점 출력

}