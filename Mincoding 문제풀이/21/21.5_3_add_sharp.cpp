#include <iostream>

using namespace std;

int main() {
	char str[100];
	char a, b;
	int pos_a, pos_b;

	cin >> str >> a >> b;

	// 검색하며 위치저장
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == a) {
			pos_a = i;
		}
		if (str[i] == b) {
			pos_b = i;
		}
	}

	// pos_a 의 앞뒤에 #추가, pos_b도
	if (pos_a == 0) { // 첫자리인경우
		str[pos_a + 1] = '#';
	}
	else if (str[pos_a + 1] == '\0') { // 마지막글자인 경우
		str[pos_a - 1] = '#';
	}
	else {
		str[pos_a + 1] = '#';
		str[pos_a - 1] = '#';
	}


	// pos_b
	if (pos_b == 0) { // 첫자리인경우
		str[pos_b + 1] = '#';
	}
	else if (str[pos_b + 1] == '\0') { // 마지막글자인 경우
		str[pos_b - 1] = '#';
	}
	else {
		str[pos_b + 1] = '#';
		str[pos_b - 1] = '#';
	}

	cout << str;


	return 0;
}