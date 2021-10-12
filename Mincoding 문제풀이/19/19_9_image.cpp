#include <iostream>

using namespace std;

int image[4][4];

// (y,x)의 좌표를 받고, 2,3사이즈 합을 return 해주는 함수
int rectSum(int y, int x) {
	int sum=0;
	
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			int yy = y + i;
			int xx = x + j;

			if (yy < 0 || xx < 0 || yy > 3 || xx > 3) { continue; }

			sum += image[yy][xx];
		}
	}

	return sum;
}

int main() {
	

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			cin >> image[y][x];
		}
	}

	int sum;
	int max = -21e8;
	int res_y, res_x;

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			sum = rectSum(y, 0);
			
			if (sum > max) {
				max = sum;
				res_y = y;
				res_x = x;
			}
		}
	}

	cout << "(" << res_y << "," <<  res_x << ")";

	return 0;
}