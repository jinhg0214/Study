#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


bool CheckString(string s, string t) {
	int lcm = s.size() * t.size();

	string f_s, f_t;
	
	for (int i = 0; i < lcm / s.size(); i++)
		f_s += s;
	
	for (int i = 0; i < lcm / t.size(); i++)
		f_t += t;

	if (f_s == f_t) {
		return 1;
	}

	return 0;
}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	string s, t;
	cin >> s >> t;

	// 긴 문자열이 s로 가도록 설정
	if (s.size() < t.size()) swap(s, t);

	cout << CheckString(s, t);

	return 0;
}