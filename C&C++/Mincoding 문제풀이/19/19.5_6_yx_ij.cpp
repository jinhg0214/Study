#include <iostream>

using namespace std;

int main() {
	char map[3][4] = {
		'A','B','G','K',
		'T','T','A','B',
		'A','C','C','D',
	};

	char pattern[2][2];

	for (int y = 0; y < 2; y++) {
		for (int x = 0; x < 2; x++) {
			cin >> pattern[y][x];
		}
	}

	// map에 pattern이 존재하는지 확인
	int cnt = 0;

	for (int y = 0; y <= 1; y++) {
		for (int x = 0; x <= 2; x++) {
			// 패턴 0,0부터 확인
			bool flag = 0;
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 2; j++) {
					if (map[y + i][x + j] != pattern[i][j]) {
						flag = 1; // 다르다면 문제있음
						break;
					}
				}
			}
			if (flag == 0) {
				cnt++;
			}
		}
	}

	if (cnt == 1) {
		cout << "발견(1개)";
	}
	else {
		cout << "미발견";
	}

	return 0;
}