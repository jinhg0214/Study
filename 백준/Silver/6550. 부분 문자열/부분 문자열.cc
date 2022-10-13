#include <iostream>
#include <string>

using namespace std;

bool solve(string s, string t) {
	bool result = false;
	int s_len = s.length(), t_len = t.length(), cnt = 0;

	// s[0] 부터 s[s_len - 1] 까지 순서대로 문자열 t 내에 있는지 확인한다
	for (int i = 0; i < t_len; i++) {
		if (t[i] == s[cnt]) cnt++;
		if (cnt == s_len) {
			return true;
		}
	}
	return false;

}

int main() {
	// freopen_s(new FILE*, "sample_input.txt", "r", stdin);
	string s, t;
	while (cin >> s >> t) {
		bool res = solve(s, t);

		if (res == true) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}
	

	return 0;
}