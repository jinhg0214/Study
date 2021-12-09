#include <iostream>
#include <string>

using namespace std;

int main() {
	string fishbowl;
	cin >> fishbowl;
	
	int a = 0;
	int b = 0;
	int max_len = 0;

	while (1) {
		a = fishbowl.find("#", a);
		if (a == -1) break;

		b = fishbowl.find("#", a + 1);
		if (b == -1) break;

		int len = b - a - 1;
		if (max_len < len) max_len = len;

		a++;
	}

	for (int i = 0; i < max_len; i++) {
		cout << "~";
	}


	return 0;
}