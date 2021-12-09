#include <iostream>
#include <string>

using namespace std;

string decrease(string str) {
	int len = str.length();
	string res;
	for (int i = 0; i < len; i++) {
		if (str[i] == '_' || str[i] == 'A') {
			res += '_';
		}
		else {
			res += char(str[i] - 1);
		}
	}
	
	return res;
}

int main() {
	string str;
	cin >> str;

	string end(str.length(), '_');

	while (1) {
		cout << str << endl;
		if (str == end) break;
		str = decrease(str);	
	}

	return 0;
}