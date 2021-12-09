#include <iostream>

using namespace std;

int map[5][5] = {
		3,3,5,3,1,
		2,2,4,2,6,
		4,9,2,3,4,
		1,1,1,1,1,
		3,3,5,9,2
};

int directY[4] = {-1,-1,1,1};
int directX[4] = {-1,1,-1,1};

int sum(int y, int x) {
	
	int sum = 0;

	for (int i = 0; i < 4; i++) {
		int yy = y + directY[i];
		int xx = x + directX[i];
		
		if (yy < 0 || xx < 0 || yy > 5 || xx > 5) { continue; }
		sum += map[yy][xx];
	}
	return sum;
}

int main() {

	int max = -21e8;
	int res_y, res_x;

	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			int res = sum(y, x);
			if (max < res) {
				max = res;
				res_y = y;
				res_x = x;
			}
		}
	}
	cout << res_y << " " << res_x;

	return 0;
}