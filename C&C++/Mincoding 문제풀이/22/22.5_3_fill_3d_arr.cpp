#include <iostream>

using namespace std;

int main() {
	char map[3][3][3];

	char ch;

	cin >> ch;

	for(int z=0; z<3; z++){
		for (int y = 0; y < 3; y++) {
			for (int x = 0; x < 3; x++) {
				map[z][y][x] = ch;
			}
		}
		ch++;
	}

	for (int z = 0; z < 3; z++) {
		for (int y = 0; y < 3; y++) {
			for (int x = 0; x < 3; x++) {
				cout << map[z][y][x];
			}
			cout << endl;
		}
		cout << endl;
	}

	return 0;
}