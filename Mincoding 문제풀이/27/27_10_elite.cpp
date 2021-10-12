#include <iostream>

using namespace std;

int main() {
	int a[3][3] = {
		2,6,3,
		7,1,1,
		3,4,2,
	};
	int b[2][4] = {
		6,4,2,4,
		1,1,5,8,
	};
	int c[2][3] = {
		9,2,3,
		4,2,1,
	};

	int res[3][3];

	// A에서 MAX값 3개
	int max_value = 0;
	int used_a[3][3] = { 0 };
	int idx = 0;
	int max_y, max_x;

	for (int i = 0; i < 3; i++) {
		max_value = 0;
		for (int y = 0; y < 3; y++) {
			for (int x = 0; x < 3; x++) {
				if (max_value < a[y][x] && used_a[y][x] == 0) {
					max_value = a[y][x];
					max_y = y;
					max_x = x;
				}
			}
		}
		res[0][idx] = max_value;
		used_a[max_y][max_x] = 1;
		idx++;
	}
	
	// B에서 MIN 값 3개
	
	int used_b[2][4] = { 0 };
	int min_value;
	int min_y, min_x;
	idx = 0;

	for (int i = 0; i < 3; i++) {
		min_value = 21e8;
		for (int y = 0; y < 2; y++) {
			for (int x = 0; x < 4; x++) {
				if (min_value > b[y][x] && used_b[y][x] == 0) {
					min_value = b[y][x];
					min_y = y;
					min_x = x;
				}
			}
		}
		res[1][idx] = min_value;
		used_b[min_y][min_x] = 1;
		idx++;
	}

	// C에서 MIN값 2개 MAX값 1개
	//MAX
	max_value = 0;
	for (int y = 0; y < 2; y++) {
		for (int x = 0; x < 3; x++) {
			if (max_value < c[y][x]) {
				max_value = c[y][x];
			}
		}
	}
	res[2][2] = max_value;

	//MIN
	int used_c[2][3] = { 0 };
	idx = 0;
	for (int i = 0; i < 2; i++) {

		min_value = 21e8;
		for (int y = 0; y < 2; y++) {
			for (int x = 0; x < 3; x++) {
				if (min_value > c[y][x] && used_c[y][x] == 0) {
					min_value = c[y][x];
					min_y = y;
					min_x = x;
				}
			}
		}
		res[2][idx] = min_value;
		used_c[min_y][min_x] = 1;
		idx++;
	}


	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			cout << res[y][x] << " ";
		}
		cout << endl;
	}







	return 0;
}