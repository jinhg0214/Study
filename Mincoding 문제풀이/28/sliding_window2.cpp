// https://pro.mincoding.co.kr/problem/SDS_%EC%98%88%EC%8B%9D%EC%9E%A5%EC%84%9C%EB%B9%99
#include <iostream>

using namespace std;

int n;
int r;
int table[1000001];

void slideWindow() {
	
	bool satisfied = true;
	int dat[201] = { 0 }; // DAT

	// i=0 일때 dat 초기값
	// (i-r, i+r)까지의 table값을 dat에 넣어줌
	int w = r * 2 + 1;
	for (int i = 0; i < w; i++) {
		int idx = i - r;
		if (idx < 0) { idx = i - r + n; } 

		dat[table[idx]]++;
	}

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < 201; j++) { // 3개 이상이라면 컴플레인
			if (dat[j] > 2) {
				satisfied = false;
				break;
			}
		}

		// dat에 table[i+r+1]넣고
		int idx = i + r + 1;
		if (idx > n) { idx = idx % n - 1; } // 배열을 넘어간 경우 다시 앞으로 붙여줌
		dat[table[idx]]++;

		// table[i-r] 빼고
		idx = i - r;
		if (idx < 0) { idx = i - r + n; } // 배열의 앞을 참조할경우 뒤로 붙여줌
		dat[table[idx]]--;
	}

	if (satisfied == false) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
	}
}

void input() {
	cin >> n >> r;

	for (int i = 0; i < n; i++) {
		cin >> table[i];
	}
}

int main() {
	//freopen_s(new FILE*, "test.txt", "r", stdin);
	int t, i = 1;
	cin >> t;

	while (t--) {
		input();

		cout << "#" << i++ << " ";
		slideWindow();
	}
	

	return 0;
}