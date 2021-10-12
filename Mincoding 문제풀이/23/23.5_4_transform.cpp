#include <iostream>

using namespace std;

int main() {
	int arr[3][4] = {
		3,5,4,1,
		1,1,2,3,
		6,7,1,2
	};

	int input[4];

	for (int i = 0; i < 4; i++) {
		cin >> input[i];
	}

	int res[3][4] = { 0 };

	
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 4; x++) {

			// arr[y][x]의 현재 좌표의 값을 읽고, 변환
			for (int i = 0; i < 3; i++) {
				if (arr[y][x] == input[i]) {
					res[y][x] = input[i + 1];
				}				
			}
			if (arr[y][x] == input[3]) {
				res[y][x] = input[0];
			}


			if (res[y][x] == 0) {
				res[y][x] = arr[y][x];
			}

		}
	}
	
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 4; x++) {
			cout << res[y][x] << " ";
		}
		cout << endl;
	}
	


	return 0;
}