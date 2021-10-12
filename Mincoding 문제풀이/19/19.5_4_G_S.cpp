#include <iostream>

using namespace std;

int main() {
	int map[4][4] = { 0 };

	for (int i = 0; i < 3; i++) {
		char cmd;
		int line;

		cin >> cmd >> line;

		if (cmd == 'G') {
			for (int i = 0; i < 4; i++) {
				map[line][i] = 1;
			}
		}

		// S
		else {
			for (int i = 0; i < 4; i++) {
				map[i][line] = 1;
			}
		}
	}

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			cout << map[y][x] << " ";
		}
		cout << endl;
	}

	return 0;
}