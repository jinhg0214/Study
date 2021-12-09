#include <iostream>

using namespace std;


int main() {
	char str[10];
	int n, str_len = 0;

	cin >> str >> n;

	// n 이후의 문자들을 한칸씩 미룸
	for (int i = 0; str[i] != '\0'; i++) {
		str_len++;
	}


	for (int i = str_len - 1; i >= n; i--) {
		str[i + 1] = str[i];
	}
	str[n] = 'A';
	str[str_len + 1] = '\0';
	
	cout << str;


	return 0;
}