#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int L, C;
vector<char> v;
int used[16];

bool check(string str) {
	int consonant = 0;
	int vowel = 0;

	for (char ch : str) {
		
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
			vowel++;
		else
			consonant++;
	}
	if (consonant >= 2 && vowel >= 1) {
		return true;
	}
	else {
		return false;
	}
}

void recursion(string str, int level, int start) {
	if (str.size() == L) {
		if (check(str)) {
			cout << str << '\n';
		} 
		return;
	}

	for (int i = start; i < v.size(); i++) {
		if (used[i]) continue;

		used[i] = 1;
		str += v[i];

		recursion(str, level + 1, i);

		used[i] = 0;
		str.pop_back();
	}
}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> L >> C;
	v.resize(C);

	for (int i = 0; i < C; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	recursion("", 0, 0);

	return 0;
}