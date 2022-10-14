#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// freopen_s(new FILE*, "sample_input.txt", "r", stdin);
	string str;
	vector<string> vect;

	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		string tmp;
		tmp = str.substr(i); // i부터 끝까지

		vect.push_back(tmp);
	}
	sort(vect.begin(), vect.end());

	for (vector<string>::iterator iter = vect.begin(); iter != vect.end(); iter++) {
		cout << *iter << '\n';
	}

	return 0;
}