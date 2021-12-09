#include <iostream>

using namespace std;

int main() {
	int pass[4];

	for (int i = 0; i < 4; i++) {
		cin >> pass[i];
	}

	int map[4][4] = { 0 };
	int idx = 0;
	for (int i = 0; i < 4; i++) {
		idx = 0;
		for (int y = 0; y < 4; y++) {
			for (int x = 0; x < 4; x++) {
				idx++;

				if (idx == pass[i]) {
					map[y][x] = i+1;
					break;
				}


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