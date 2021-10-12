#include <iostream>
#include <string>

using namespace std;


int main() {
	string before[5] = {
		"KFC",
		"MC",
		"BICMAC",
		"SHACK",
		"SONY"
	};

	string after[5] = {
		"#BBQ#",
		"#BBQ#",
		"#MACBOOK#",
		"#SHOCK#",
		"#NONY#"
	};

	string input;

	cin >> input;

	for (int i = 0; i < 5; i++) {
		// 첫번째 검사
		int pos = input.find(before[i]);

		while (pos != string::npos) {
			// 문자를 바꿈
			input.replace(pos, before[i].size(), after[i]);
			pos = input.find(before[i],pos+1);
		}
	}

	cout << input;

	return 0;
}