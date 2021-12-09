#include <iostream>

using namespace std;

int main() {
	int map[5][4];

	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 4; x++) {
			cin >> map[y][x];
		}
	}


	for (int y = 1; y < 5; y++) {
		bool isFull = true;

		for (int x = 0; x < 4; x++) {
			if (map[y][x] == 0) {
				isFull = false;
			}
		}
		// 줄이 꽉찼다면 터트림
		if (isFull == true) {
			// 현재줄을 일단 0으로 다 채우고
			for (int x = 0; x < 4; x++) {
				map[y][x] = 0;
			}
			// 위에줄 복사해오기
			for (int x = 0; x < 4; x++) {
				map[y][x] = map[y-1][x];
			}
			// 위에줄 0으로 채우기
			for (int x = 0; x < 4; x++) {
				map[y-1][x] = 0;
			}
		}
	}


	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 4; x++) {
			cout << map[y][x] << " ";
		}
		cout << endl;
	}
}