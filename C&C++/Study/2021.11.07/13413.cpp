// https://www.acmicpc.net/problem/13413
// 오셀로 뒤집기
/*
문자열 입력 받고 타겟 문자열로 만드는데 몇번 '뒤집기' 또는 'swap'이 필요한가?

-> DFS로 시도했으니 시간초과!
수학문제였음
*/

#include <iostream>
#include <string>

using namespace std;

string tar;
string str;
int max_lv;
int ans = 21e8;

void swap(int n, int m) {
	if (str[n] == str[m]) return; // 같은 색이라면 바꾸는 의미가 없다
	else {
		char ch = str[n];
		str[n] = str[m];
		str[m] = ch;
	}
}

void flip(int n) {
	if (str[n] == 'W') { str[n] = 'B'; return; }
	if (str[n] == 'B') { str[n] = 'W'; return; }
}

void DFS(int Lv, int start) {
	if (Lv > max_lv) { return; }
	// 바닥조건 
	if (str == tar) {
		if (Lv < ans) {
			ans = Lv;
		}
		return;
	}

	for (int i = start; i < str.length(); i++) {
		if (i < str.length() - 1) {
			swap(i, i + 1);
			DFS(Lv + 1, i);
			swap(i, i + 1);
		}

		// i번째를 뒤집어본다
		flip(i);
		DFS(Lv + 1, i);
		flip(i); // 원상복귀
	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	int T;
	cin >> T;

	while(T--) {
		cin >> max_lv >> str >> tar;
		ans = 21e8;
		DFS(0, 0);
		cout << ans << endl;
	}	

	return 0;
}