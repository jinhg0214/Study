#include <iostream>

using namespace std;

int main() {
	int map[3][2][3];

	int a, b;

	cin >> a >> b;

	for (int z = 0; z < 3; z++) {
		for (int y = 0; y < 2; y++) {
			if (y == 0) {
				for (int x = 0; x < 3; x++) {
					map[z][y][x] = a;
				}
			}
			else if (y == 1) {
				for (int x = 0; x < 3; x++) {
					map[z][y][x] = b;
				}
			}			
		}
	}

	for (int z = 0; z < 3; z++) {
		for (int y = 0; y < 2; y++) {
			for (int x = 0; x < 3; x++) {
				cout << map[z][y][x] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}


	return 0;
}