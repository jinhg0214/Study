#include <iostream>
#include <string>

using namespace std;

int main() {
	string input;
	cin >> input;

	int res = 0;
	int length = input.size();
	int k = 1; // 10^0부터 시작
	for (int i = 1; i < length; i++) {
		int tmp = (9 * k) * i;
		res += tmp;
		k *= 10;
	}

	res += (stoi(input) - k + 1)* length;
	
	cout << res;
	
	return 0;
}