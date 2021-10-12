#include <iostream>

using namespace std;

int main() {

	char str[11];
	cin >> str;

	int dat[26] = { 0 };

	for (int i = 0; str[i] != '\0'; i++) {
		int idx = (int)(str[i] - 'A');
		dat[idx]++;
	}

	int cnt = 0;

	for (int i = 0; i < 26; i++) {
		if (dat[i] != 0) {
			cnt++;
		}
	}

	cout << cnt << "종류";

	

	return 0;
}