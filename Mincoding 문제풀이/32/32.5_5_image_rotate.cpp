#include <iostream>

using namespace std;

int n, k;
int map[10][10];

void Input() {
	cin >> n >> k;

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> map[y][x];
		}
	}
}

void Rotate() {

	int tmp[10][10];

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			tmp[y][x] = map[(n - 1) - x][y];
		}
	}

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			map[y][x] = tmp[y][x];
		}
	}
}

void showMap() {
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cout << map[y][x] << " ";
		}
		cout << endl;
	}
}

int main() {
	freopen_s(new FILE*, "test.txt", "r", stdin);
	Input();

	while (k--) {
		Rotate();
	}

	showMap();

	return 0;
}