#include <iostream>

using namespace std;

int main() {
	char str[15];

	cin >> str;

	// DAT
	int dat[26] = { 0 };
	for (int i = 0; str[i] != '\0'; i++) {
		int idx = str[i] - 'A';
		dat[idx]++;
	}

	// MAX
	int max = -21e8;
	int max_i = 0;

	for (int i = 0; i < 26; i++) {
		if (max < dat[i]) {
			max = dat[i];
			max_i = i;
		}
	}

	cout << (char)('A' + max_i);
	


	return 0;
}