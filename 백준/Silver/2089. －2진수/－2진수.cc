#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;

	if (n == 0) {
		cout << 0;
		return 0;
	}

	string res;

	while (n != 0) {
		if (n % -2 == 0) {
			res = '0' + res;
			n /= -2;
		}
		else {
			res = '1' + res;
			n = (n - 1) / -2; // c, c++ 특성상 음수를 나눌 때 값이 python과 다름.
		}
	}

	cout << res;

	return 0;
}