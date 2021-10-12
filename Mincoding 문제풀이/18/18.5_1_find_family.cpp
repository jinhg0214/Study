#include <iostream>

using namespace std;

int main() {
	char arr[2][3] = {
		'G','K','G'
	};

	for (int i = 0; i < 3; i++) {
		cin >> arr[1][i];
	}

	// 같은 문자가 3개 이상인지 확인
	// DAT 사용
	int dat[26] = { 0 };

	for (int y = 0; y < 2; y++) {
		for (int x = 0; x < 3; x++) {
			int idx = arr[y][x] - 'A';
			dat[idx]++;
		}
	}

	bool flag = 0;
	for (int i = 0; i < 26; i++) {
		if (dat[i] >= 3) {
			flag = 1;
			break;
		}
	}

	if (flag == 1) {
		cout << "있음";
	}
	else {
		cout << "없음";
	}

	return 0;
}