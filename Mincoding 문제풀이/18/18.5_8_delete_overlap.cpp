#include <iostream>

using namespace std;

int main() {

	char str[10];
	cin >> str;

	// dat
	int dat[6] = { 0 };
	for (int i = 0; str[i] != '\0'; i++) {
		dat[str[i] - 'A']++;
	}

	// 중복 알파벳 제거 후, 알파벳 순서로 출력
	for (int i = 0; i < 6; i++) {
		if (dat[i] != 0) {
			cout << (char)('A' + i);
		}
	}

	return 0;
}