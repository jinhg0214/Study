#include <iostream>

using namespace std;

int main() {
	char str[100];
	int str_len = 0;

	cin >> str;

	for (int i = 0; str[i] != '\0'; i++) {
		str_len++;
	}

	for (int i = 0; i < str_len; i++) {
		for (int j = 0; j <= i; j++) {
			cout << str[j];
		}
		cout << endl;
	}

	return 0;
}