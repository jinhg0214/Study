#include <iostream>
#include <string>

using namespace std;

int main() {
	string str[6] = {
		"ABCD",
		"ABCE",
		"AGEH",
		"EIEI",
		"FEQE",
		"ABAD",
	};
	int result[6] = { 1,1,1,1,1,1 };
	string input;
	cin >> input;

	for (int i = 0; i < 6; i++) {
		if (result[i] == 0) continue;  // 이미 탈락했으면 안봄
		
		for (int j = 0; j < 4; j++) {
			if (input[j] == '?') continue; // ? 는 안봄
			if (str[i][j] != input[j]) {
				result[i] = 0;
				break;
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < 6; i++) {
		if (result[i] == 1) {
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}