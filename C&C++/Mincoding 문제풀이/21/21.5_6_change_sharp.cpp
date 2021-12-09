#include <iostream>

using namespace std;

int main() {
	int map[4][3] = {
		1,5,3,
		4,5,5,
		3,3,5,
		4,6,2
	};

	int a, b;

	cin >> a >> b;

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 3; x++) {
			if (map[y][x] >= a && map[y][x] <= b) {
				map[y][x] = 0;
			}
		}
	}

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 3; x++) {
			if (map[y][x] == 0) {
				cout << "#" << " ";
			}
			else {
				cout << map[y][x] << " ";
			}

			
		}
		cout << endl;
	}

	return 0;
}