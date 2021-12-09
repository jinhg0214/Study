#include <iostream>
#include <string>

using namespace std;

int main() {
	string a;
	string b ;
	cin >> a >> b;

	string res;
	for (int i = 0; i <= a.size(); i++) {
		for (int j = i; j < a.size(); j++) {
			string tmp_str = a.substr(i, j - i + 1);
			// cout << tmp_str << endl;
			if (b.find(tmp_str) != -1) {
				// 존재하면 길이 비교
				if (res.length() < tmp_str.length()) {
					res = tmp_str;
				}
			}
		}
	}

	cout << res;

	return 0;
}