#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	if (n == 0) {
		cout << 0;
		return 0;
	}

	string res = "";
	while (n != 0) {
		if (n % -2 == 0) {
			res = '0' + res; // 나누어 떨어지면 앞에 0을 추가
			n /= -2;
		}
		else {
			res = '1' + res;
			n = (n-1) / -2;
		}
	}

	cout << res;

	return 0;
}