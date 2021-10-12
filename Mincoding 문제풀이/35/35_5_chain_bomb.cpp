#include <iostream>

using namespace std;

int n;
int map[1001][1001];

int directY[4] = { 0,-1,0,1 };
int directX[4] = { -1,0,1,0 };

void Init() {
	cin >> n;

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> map[y][x];
		}
	}

}

void Bomb(int time) {

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (map[y][x] == time) { // 터질차레라면
				map[y][x] = 0;
				for (int i = 0; i < 4; i++) {
					int dy = y + directY[i];
					int dx = x + directX[i];

					if (dy < 0 || dx < 0 || dy > n-1 || dx > n-1) { continue; }

					map[dy][dx] = 0;

				}

			}
		}
	}
}

bool IsClear() {
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (map[y][x] != 0) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	freopen_s(new FILE*, "test.txt", "r", stdin);

	Init();

	int sec = 0;
	while (IsClear() == false) {
		sec++;

		Bomb(sec);
	}
	cout << sec <<"초";

	return 0;
}