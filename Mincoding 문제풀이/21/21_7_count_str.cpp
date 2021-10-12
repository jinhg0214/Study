#include <iostream>
#include <string>

using namespace std;

void str_len(int Lv) {

	if (Lv == 1) {
		cout << Lv << " ";
		return;
	}
	cout << Lv << " ";

	str_len(Lv - 1);

	cout << Lv << " ";
}

int main() {
	string str;

	cin >> str;

	int sz = str.size();

	str_len(sz);


	return 0;
}