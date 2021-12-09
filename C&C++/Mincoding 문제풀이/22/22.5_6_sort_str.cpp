#include <iostream>
#include <string.h>

using namespace std;

int main() {
	char str[4][20];
	int str_len[4] = { 0 };

	// 각 문장 입력
	for (int i = 0; i < 4; i++) {
		cin >> str[i];
	}

	// 문장 길이 구하기
	for (int i = 0; i < 4; i++) {
		for (int j = 0; str[i][j] != '\0'; j++) {
			str_len[i]++;
		}
	}

	// 길이순으로 정렬
	char tmp[20];
	int tmp_len;

	// sort
	for (int i = 0; i < 4; i++) {
		for (int j = i; j < 4; j++) {
			if (str_len[i] > str_len[j]) {
				strcpy(tmp, str[i]);
				strcpy(str[i], str[j]);
				strcpy(str[j], tmp);

				tmp_len = str_len[i];
				str_len[i] = str_len[j];
				str_len[j] = tmp_len;
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		cout << str[i] << endl;
	}

	return 0;
}