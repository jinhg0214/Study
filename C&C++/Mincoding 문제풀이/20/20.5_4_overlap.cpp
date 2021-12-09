#include <iostream>

using namespace std;

int main() {
	//freopen_s(new FILE *, "test.txt", "r", stdin);

	int arr[2][4][4];

	for (int t = 0; t < 2; t++) {
		for (int y = 0; y < 4; y++) {
			for (int x = 0; x < 4; x++) {
				cin >> arr[t][y][x];
			}
		}
	}

	bool flag = 0;
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (arr[0][y][x] == 1 && arr[1][y][x] == 1) { // 두 배열 모드 1로 되어있는경우
				flag = 1;
				break;
			}
		}
	}

	if (flag == 1) {
		cout << "걸리다";
	}
	else {
		cout << "걸리지않는다";
	}
	

	return 0;
}