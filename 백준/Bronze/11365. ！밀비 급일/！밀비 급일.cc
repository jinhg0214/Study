#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	string str;
	while (1) {
		getline(cin, str);
		if (str == "END") break;
		reverse(str.begin(), str.end());
		cout << str << endl;
	}
	
	return 0;
}