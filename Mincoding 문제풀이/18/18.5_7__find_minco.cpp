#include <iostream>

using namespace std;

int main() {

	char str[20] = "MINCODING";

	// DAT
	int dat[26] = { 0 };

	for (int i = 0; str[i] != '\0'; i++) {
		int idx = str[i] - 'A';
		dat[idx]++;
	}

	// find
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		char ch;
		cin >> ch;

		int idx = ch - 'A';
		if (dat[idx] != 0) {
			cout << "O";
		}
		else {
			cout << "X";
		}
	}



	return 0;
}