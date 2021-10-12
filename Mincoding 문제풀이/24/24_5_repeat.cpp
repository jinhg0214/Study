#include <iostream>

using namespace std;


int main() {
	string lyrics;

	cin >> lyrics;

	int a, b, c;

	cin >> a >> b >> c;

	

	for (int i = 0; i < c; i++) {
		cout << lyrics.substr(a, b-a+1);
	}

	return 0;
}