#include <iostream>

using namespace std;

int main() {
	int arr[6];

	for (int i = 0; i < 6; i++)
		cin >> arr[i];

	int dat[10] = { 0 };
	for (int i = 0; i < 6; i++) {
		int idx = arr[i];
		dat[idx]++;
	}

	bool flag = 0;
	for (int i = 0; i <= 9; i++) {
		if (dat[i] > 1) {
			flag = 1;
			break;
		}
	}

	if (flag == 1) {
		cout << "도플갱어 발견";
	}
	else {
		cout << "미발견";
	}


	return 0;
}