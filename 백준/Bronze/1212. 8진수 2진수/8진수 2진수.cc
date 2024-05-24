#include <iostream>
#include <string>

using namespace std;

int main() {

	string octal;
	string bin[8] = { "000" , "001", "010", "011", "100", "101", "110", "111" };

	cin >> octal;
	int tmp;
	for (int i = 0; i < octal.size(); i++) {
		tmp = octal[i] - '0';
		if (i == 0) cout << stoi(bin[tmp]); // stoi로 첫 0을 지울 수 있음 
		else cout << bin[tmp];
	}
}