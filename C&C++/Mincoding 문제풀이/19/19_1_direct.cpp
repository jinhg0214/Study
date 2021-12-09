#include <iostream>

using namespace std;

int directY[4] = {0,-1,0,1};
int directX[4] = {-1,0,1,0};

int main() {
	int arr[3][3] = {
		3,5,4,
		1,1,2,
		1,3,9
	};

	int y, x;
	int sum = 0;

	cin >> y >> x;

	for (int i = 0; i < 4; i++) {
		int yy = y + directY[i];
		int xx = x + directX[i];

		if (yy < 0 || xx < 0 || yy > 2 || xx > 2) { continue; }
		sum += arr[yy][xx];


	}

	cout << sum;


	return 0;
}