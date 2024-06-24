#include <bits/stdc++.h>

using namespace std;

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

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);

	int L, C;
	vector<char> v;
	cin >> L >> C;
	v.resize(C);

	for (int i = 0; i < C; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	vector<int> idx; // 조합을 위한 벡터
	for (int i = 0; i < L; i++) {
		idx.push_back(0);
	}
	for (int i = 0; i < C-L; i++) {
		idx.push_back(1);
	}

	do {
		string str = "";
		for (int i = 0; i < idx.size(); i++) {
			if (idx[i] == 0) {
				str += v[i];
			}
		}
		if (check(str)) {
			cout << str << '\n';
		}
	} while (next_permutation(idx.begin(), idx.end()));

	return 0;
}