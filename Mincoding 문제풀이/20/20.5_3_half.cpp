#include <iostream>
#include <string.h>

using namespace std;

int main() {
	char str[20];

	cin >> str;

	int str_len = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		str_len++;
	}

	char str_front[10], str_end[10];

	int i, j;
	for (i = 0; i < str_len / 2; i++) {
		str_front[i] = str[i];
	}str_front[i] = '\0';

	i = 0;
	for (j = str_len/2; j < str_len; j++) {
		str_end[i] = str[j];
		i++;
	}str_end[i] = '\0';

	if (strcmp(str_front, str_end) == 0) {
		cout << "동일한문장";
	}
	else {
		cout << "다른문장";
	}

}