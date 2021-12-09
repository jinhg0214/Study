#include <iostream>
#include <string>

using namespace std;

int main() {
	string cipher[5] = {
		"Jason",
		"Dr.tom",
		"EXEXI",
		"GK12P",
		"POW"
	};

	string input;
	bool flag = 0;

	cin >> input;

	for (int i = 0; i < 5; i++) {
		if (input == cipher[i]) {
			flag = 1;
			break;
		}
	}

	if (flag == 1) {
		cout << "암호해제" << endl;
	}
	else {
		cout << "암호틀림" << endl;
	}

	return 0;
}