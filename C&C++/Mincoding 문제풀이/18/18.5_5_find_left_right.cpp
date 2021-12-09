#include <iostream>
#include <cstring>

using namespace std;

int findChar(char str[], char ch,int cmd) {

	// 앞에서부터 검색
	if (cmd == 0) {
		for (int i = 0; str[i] != '\0'; i++) {
			if (str[i] == ch) {
				return i;
			}
		}
	}

	// 뒤에서부터 검색
	else {
		int str_len = strlen(str);
		for (int i = str_len-1; i >= 0 ; i--) {
			if(str[i] == ch)
				return i;
		}
	}

	return -1;
}

int main() {
	char str[10] = "ATKPTCABC";

	char left, right;

	cin >> left >> right;

	int pos_left = findChar(str, left, 0);

	int pos_right = findChar(str, right, 1);

	int res = pos_right - pos_left;

	cout << res;


	return 0;
}