#include <iostream>

using namespace std;

int main() {
	//freopen_s(new FILE*, "test.txt", "r", stdin);
	char map[4][3];

	for (int y = 0; y <= 3; y++) {
		for (int x = 0; x <= 2; x++) {
			cin >> map[y][x];
		}
	}

	// 현 위치에서 아래에 빈 공간이 몇칸 있는지 계산한다
	int drop;

	for (int y = 3; y >= 0; y--) {
		for (int x = 0; x <= 2; x++) {
			if (map[y][x] != '_') {
				drop = 0;

				// 현재 y좌표에서 아래 y좌표들 중 빈공간을 계산
				for (int i = y; i < 4; i++) {
					if (map[i][x] == '_') {
						drop++;
					}
				}
				if (drop == 0)continue;
				// 빈 공간만큼 이동시켜준다
				map[y+drop][x] = map[y][x];
				map[y][x] = '_'; // 원래 공간은 비워줌
				 
			}
		}
	}

	for (int y = 0; y <= 3; y++) {
		for (int x = 0; x <= 2; x++) {
			cout << map[y][x];
		}
		cout << endl;
	}


	return 0;
}