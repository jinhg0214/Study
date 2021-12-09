#include <iostream>

using namespace std;

int main() {
	char map[2][2][3] = {
		{'A','T','B',
		 'C','C','B'},
		{'A','A','A',
		 'B','B','C'}
	};

	char ch;

	cin >> ch;

	for (int t = 0; t < 2; t++) {
		for (int y = 0; y < 2; y++) {
			for (int x = 0; x < 3; x++) {
				if (map[t][y][x] == ch) {
					cout << "발견";
					return 0;
				}
			}
		}
	}
	cout << "미발견";

	return 0;
}