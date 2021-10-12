#include <iostream>
#include <string>

using namespace std;

string str;
string res;

// 중복 가능 -> 
void Kimbob(int Lv, int start) {

	if (Lv == 3) {
		cout << res << endl;
		return;
	}
	
	for (int x = start; x < str.length(); x++) {
		res += str[x];
		Kimbob(Lv + 1, x);
		res.erase(res.length() - 1, 1);
	}
}

int main() {
	
	cin >> str;

	Kimbob(0, 0);

	return 0;
}