#include <iostream>
#include <string>

using namespace std;

void binToOctal(string input) {

	for (int i = 0; i < input.size(); i += 3) {
		int num = (input[i] - '0') * 4 + (input[i + 1] - '0') * 2 + (input[i + 2] - '0') * 1;
		cout << num;
	}
}

int main() {
	string input;
	cin >> input;

	// 3자리씩 끊어질 수 있도록 맞춤
	while (input.size() % 3 != 0) {
		input = '0' + input;
	}

	binToOctal(input);

	return 0;
}