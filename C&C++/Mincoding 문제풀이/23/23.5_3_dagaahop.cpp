#include <iostream>

using namespace std;

int main() {
	int arr[4][4];

	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			cin >> arr[y][x];
		}
	}

	// 가로 계산
	for (int y = 0; y < 3; y++) {
		arr[y][3] = arr[y][0] + arr[y][1] + arr[y][2];
	}

	// 세로 계산
	for (int x = 0; x < 3; x++) {
		arr[3][x] = arr[0][x] + arr[1][x] + arr[2][x];
	}

	// 대각선 계산
	arr[3][3] = arr[0][0] + arr[1][1] + arr[2][2];

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			cout << arr[y][x] << " ";
		}
		cout << endl;
	}

	return 0;
}