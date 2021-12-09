#include <iostream>
#include <string>

using namespace std;

int main() {
	
	string str;
	int dat[26] = { 0 };

	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		dat[str[i]-'A'] ++;
	}

	int max = -21e8, min = 21e8;
	int maxi, mini;

	for (int i = 25; i >= 0; i--) {
		if (max < dat[i]) {
			max = dat[i];
			maxi = i;
		}
		if (min >= dat[i]) {
			min = dat[i];
			mini = i;
		}
	}

	cout << (char)('A' + maxi) << endl << (char)('A' + mini);



	return 0;
}