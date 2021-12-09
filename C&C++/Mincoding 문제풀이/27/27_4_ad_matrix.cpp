#include <iostream>

using namespace std;

int main(){
	int map[4][4];

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			cin >> map[y][x];
		}
	}

	int max_row = -1, max_val = 0;
	
	for (int y = 0; y < 4; y++) {
		int cnt = 0;
		for (int x = 0; x < 4; x++) {
			if (map[y][x] == 1) {
				cnt++;
			}
		}
		if (max_val < cnt) {
			max_val = cnt;
			max_row = y;
		}
	}
	
	cout << (char)('A' + max_row);

	return 0;
}