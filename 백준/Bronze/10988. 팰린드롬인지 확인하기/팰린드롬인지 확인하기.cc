#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string str) {
	int len = str.length();
	bool flag = true;
	
	for (int i = 0; i < len/2; i++) {
		if (str[i] != str[len - 1 - i]) {
			flag = false;
		}
		if (flag == false) {
			break;
		}
	}
	
	

	return flag;
}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);

	string str;
	cin >> str;

	if (isPalindrome(str)) {
		cout << "1" << endl;
	}
	else {
		cout << "0" << endl;
	}


	return 0;
}