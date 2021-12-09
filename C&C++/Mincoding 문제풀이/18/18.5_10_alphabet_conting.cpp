#include <iostream>

using namespace std;

int main() {
	char str[10];

	cin >> str;

	int dat[26] = { 0 };
	for (int i = 0; str[i] != '\0'; i++) {
		int idx = str[i] - 'A';
		dat[idx]++;
	}

	for (int i = 0; i < 26; i++) {
		if (dat[i] != 0) {
			char ch = (char)('A' + i);
			cout << ch << ":" << dat[i] << endl;
		}
	}


	return 0;
}