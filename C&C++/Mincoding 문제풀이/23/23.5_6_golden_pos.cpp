#include <iostream>

using namespace std;



int main() {
	char map[4][4] = {
		'A','B','C','D',
		'B','B','A','B',
		'C','B','A','C',
		'B','A','A','A',
	};
	char input[4][4];
	int alphabet[4] = { 0 };

	// 입력
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			cin >> input[y][x];
		}
	}

	// DAT를 이용해 저장
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (input[y][x] == map[y][x]) {
				alphabet[input[y][x] - 'A']++;
			}
		}
	}
	
	int maxi = -21e8, idx = 0;

	for (int i = 0; i < 4; i++) {
		if (maxi < alphabet[i]) {
			maxi = alphabet[i];
			idx = i;
		}
	}

	cout << (char)('A' + idx);


	return 0;
}