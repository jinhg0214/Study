#include <iostream>

using namespace std;


int main() {
	char str[10];
	int n, str_len = 0;

	cin >> str >> n;

	// str[n]부터 한칸씩 땡김
	for (int i = n; str[i] != '\0'; i++) {
		str[i] = str[i + 1];
	}

	cout << str;



	return 0;
}