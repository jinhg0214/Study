#include <iostream>

using namespace std;

int map[4][8];

void Input() {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 8; x++) {
			cin >> map[y][x];
		}
	}
}

// y, x좌표를 시작점으로 만들 수 있는 최대 직사각형의 땅크기 리턴
int FindPrice(int y, int x) {
	int res = 0;
	int y_idx = y, x_idx = x;

	while (1) {
		if (map[y][x_idx] == 0) break;
		x_idx++;
		if (x_idx >= 8) break;
	}

	while (1) {
		bool flag = false;

		for (int i = x; i < x_idx; i++) {
			if (map[y_idx][i] == 0) {
				flag = true;
			}
		}

		if (flag == true) break;
		y_idx++;
		if (y_idx >= 4) break;
	}

	for (int i = y; i < y_idx; i++) {
		for (int j = x; j < x_idx; j++) {
			res += map[i][j];
		}
	}
	
	return res;
}

int main() {
	// freopen_s(new FILE*, "test.txt", "r", stdin);
	Input();

	int max_price = 0;
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 8; x++) {
			if (map[y][x] == 0) continue;
			int res = FindPrice(y, x);
			max_price = max(max_price, res);
		}
	}

	cout << max_price;

	return 0;
}