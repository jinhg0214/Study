#include <iostream>
#include <string>

using namespace std;

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	int N;
	int cnt[26] = { 0 }; // 꼭 0으로 초기화 해줄 것!!
	string str;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> str;
		
		cnt[str[0] - 'a']++;
	}

	bool flag = false;

	for (int i = 0; i < 26; i++) {
		if (cnt[i] > 4) {
			cout << char('a' + i);
			flag = true;
		}
	}

	if (flag == false) {
		cout << "PREDAJA";
	}

	return 0;
}