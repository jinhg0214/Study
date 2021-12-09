#include <iostream>

using namespace std;


bool isExist(char str[][10], char ch) {

	for (int t = 0; t < 2; t++) {
		for (int i = 0; str[t][i] != '\0'; i++) {
			if (str[t][i] == ch) {
				return true;
			}
		}
	}
	return false;
}



int main() {
	char str[2][10] = {
		"A79TKQ",
		"MINCOD"
	};

	char ch[2];

	cin >> ch[0] >> ch[1];

	for (int i = 0; i < 2; i++) {
		if (isExist(str, ch[i])) {
			cout << ch[i] << " : 존재" << endl;
		}
		else {
			cout << ch[i] << " : 없음" << endl;
		}
	}

}