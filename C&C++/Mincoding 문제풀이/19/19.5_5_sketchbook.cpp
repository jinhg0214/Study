#include <iostream>

using namespace std;

struct Sketchbook {
	char image[3][3];
};

int main() {
	Sketchbook s;

	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			cin >> s.image[y][x];
		}
	}

	// DAT 이용
	int dat[26] = { 0 };

	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			int idx = s.image[y][x] - 'A';
			dat[idx]++;
		}
	}

	// 한번이라도 사용됬으면 출력
	for (int i = 0; i < 26; i++) {
		if (dat[i] != 0) {
			cout << (char)('A' + i);
		}
	}

	return 0;
}