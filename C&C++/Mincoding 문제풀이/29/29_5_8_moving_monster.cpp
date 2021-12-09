#include <iostream>
#include <Windows.h>

using namespace std;

int directY[4] = { 0,1,0,-1 };
int directX[4] = { 1,0,-1,0 };

char map[4][3];

void tick(int t) {
	int time = (t - 1)%4;
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 3; x++) {
			if (map[y][x] != '_' && map[y][x] != '#') {
				int dy = y + directY[time];
				int dx = x + directX[time];

				if (dy < 0 || dx < 0 || dy > 3 || dx > 2) continue;
				if (map[dy][dx] == '#' || 
					map[dy][dx] == 'A' ||
					map[dy][dx] == 'C' || 
					map[dy][dx] == 'D') continue;

				map[dy][dx] = map[y][x];
				map[y][x] = '_';
			}
		}
	}

}

void showMap() {
	system("cls");
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 3; x++) {
			cout << map[y][x];
		}
		cout << endl;
	}
	Sleep(1000);
}

int main() {
	freopen_s(new FILE*, "test.txt", "r", stdin);

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 3; x++) {
			cin >> map[y][x];
		}
	}
	int t = 1;
	while (t <= 5) {
		tick(t);

		showMap();
		t++;
	}


	return 0;
}