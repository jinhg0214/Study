#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	cin >> str;

    // bubble sort
	for (int i = 0; i < str.size(); i++) {
		for (int j = i; j < str.size(); j++) {
			if (str[i] < str[j]) {
				char tmp;
				tmp = str[i];
				str[i] = str[j];
				str[j] = tmp;
			}
		}
	}

	cout << str;

	return 0;
}