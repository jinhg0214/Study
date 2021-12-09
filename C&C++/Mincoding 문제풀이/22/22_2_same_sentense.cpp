#include <iostream>
#include <cstring>

using namespace std;

int main(){

	char str[3][20];
	bool flag = 0;

	for (int i = 0; i < 3; i++) {
		cin >> str[i];
	}

	// 세문장이 같은경우
	if (strcmp(str[0], str[1]) == 0 && strcmp(str[1], str[2]) == 0) {
		cout << "WOW";
	}
	else if (strcmp(str[0], str[1]) == 0 || strcmp(str[1], str[2]) == 0) {
		cout << "GOOD";
	}
	else {
		cout << "BAD";
	}

	return 0;
}