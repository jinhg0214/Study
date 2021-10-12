#include <iostream>

using namespace std;

int main(){
	int map[3][3] = {
		0,5,4,
		3,0,0,
		0,0,1,
	};

	/*
	 1회      2회      3회
	0 3 0    1 0 0    4 0 1
	0 0 5 -> 0 0 3 -> 5 0 0
	1 0 4    4 5 0    0 3 0
	*/

	int roll;

	cin >> roll;

	for (int k = 0; k < roll; k++) {
		int tmp[3][3];
		// map -> tmp cpy
		for (int y = 0; y < 3; y++) {
			for (int x = 0; x < 3; x++) {
				tmp[y][x] = map[y][x];
			}
		}

		// tmp를 roll
		for (int y = 0; y < 3; y++) {
			for (int x = 0; x < 3; x++) {
				tmp[y][x] = map[2-x][y];
			}
		}

		// tmp -> map cpy;
		for (int y = 0; y < 3; y++) {
			for (int x = 0; x < 3; x++) {
				map[y][x] = tmp[y][x];
			}
		}
	}
	
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			if (map[y][x] == 0) {
				cout << "_";
			}
			else cout << map[y][x];
		}
		cout << endl;
	}
	

	return 0;
}