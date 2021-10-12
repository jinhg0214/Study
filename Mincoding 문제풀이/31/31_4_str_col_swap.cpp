#include <iostream>
#include <string.h>

using namespace std;

int main() {
	char str[5][6];
	
	for (int i = 0; i < 5; i++) {
		cin >> str[i];
	}

	for (int i = 0; i < 5; i++) {
		char tmp = str[i][1];
		str[i][1] = str[i][3];
		str[i][3] = tmp;
	}

	bool flag = false;
	for (int i = 0; i < 5; i++) {
		if (strcmp(str[i], "MAPOM") == 0) {
			flag = true;
			break;
		}
	}

	if (flag == true) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}

	return 0;
}