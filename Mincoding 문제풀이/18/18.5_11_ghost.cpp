#include <iostream>

using namespace std;

bool findSubstr(char str[], char target[]) {

	int i = 0, j = 0;

	while (str[i] != '\0' && target[j] != '\0') {

		if (str[i] == target[j]) {
			i++;
			j++;
		}
		else {
			i++;
			j = 0;
		}
	}


	if ( target[j] == '\0'){
		return true;
	}
	else {
		return false;
	}
}

int main() {
	char str[100];

	cin >> str;

	char target[6] = "GHOST";

	if (findSubstr(str, target) == true) {
		cout << "존재";
	}
	else {
		cout << "존재하지 않음";
	}


	return 0;
}