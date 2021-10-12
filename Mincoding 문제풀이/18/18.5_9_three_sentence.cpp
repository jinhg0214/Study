#include <iostream>

using namespace std;

int main() {
	char str[3][100];

	for (int i = 0; i < 3; i++) {
		cin >> str[i];
	}

	// dat
	int dat[26] = { 0 };
	for (int y = 0; y < 3; y++) {
		for (int i = 0; str[y][i] != '\0'; i++) {
			int idx = str[y][i] - 'A';
			dat[idx]++;
		}
	}

	// 중복확인
	bool flag = 0;

	for (int i = 0; i < 26; i++) {
		if (dat[i] > 1) {
			flag = 1;
			break;
		}
	}

	if (flag == 1) {
		cout << "No";
	}
	else {
		cout << "Perfect";
	}


	return 0;
}