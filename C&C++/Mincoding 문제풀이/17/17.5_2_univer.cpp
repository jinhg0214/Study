#include <iostream>

using namespace std;

bool isExist(int arr[], int univer) {

	for (int i = 0; i < 6; i++) {
		if (arr[i] == univer) {
			return true;
		}
	}
	return false;
}

int main() {
	int arr[6] = {
		3,7,4,1,2,6
	};

	int univer[2][2];

	for (int y = 0; y < 2; y++) {
		for (int x = 0; x < 2; x++) {
			cin >> univer[y][x];
		}
	}

	bool flag = 0;

	for (int y = 0; y < 2; y++) {
		for (int x = 0; x < 2; x++) {
			if (isExist(arr, univer[y][x])) {
				flag = 1;
			}
			else {
				flag = 0;
			}

			if (flag == 1) {
				cout << "OK ";
			}
			else {
				cout << "NO ";
			}
		}
		cout << endl;
	}

	

	return 0;
}