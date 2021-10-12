#include <iostream>
#include <string>

using namespace std;

// 246 -> 642
int Reverse(int n) {
	string str = to_string(n);

	string tmp;

	for (int i = 0; i < str.size(); i++) {
		tmp += str[str.size() - 1 - i];
	}

	int res =stoi(tmp);

	return res;
}

int main() {
	int p, n;
	cin >> p >> n;

	int res = p;
	for (int i = 0; i < n; i++) {
		// 2곱함
		res = 2 * res;
		// 뒤집음
		res = Reverse(res);
	}

	cout << res;
	return 0;
}