#include <iostream>

using namespace std;


int main() {
	char arr[9];
	int alphabet[26] = { 0 };

	for (int i = 0; i < 8; i++) {
		cin >> arr[i];

		alphabet[arr[i] - 'A']++;
	}
	int max= 0, index;
	for (int i = 0; i < 26; i++) {
		if (max < alphabet[i]) {
			max = alphabet[i];
			index = i;
		}
	}

	cout << (char)('A' + index);
	

	


	return 0;
}