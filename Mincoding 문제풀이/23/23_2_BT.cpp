// 네글자 입력
// B와 T는 인접하지 않게!!
// Lv : 4 Br : 4

#include <iostream>

using namespace std;

char path[10];
char name[5];
int cnt = 0;

void go(int Lv) {

	// 가지치기 조건 B와 T가 붙어있으면? 안됨!!
	if (path[Lv - 1] == 'B' && path[Lv - 2] == 'T') return;
	if (path[Lv - 1] == 'T' && path[Lv - 2] == 'B') return;

	if (Lv == 4) { // 성공한경우
		cnt++;
		return;
	}

	for (int x = 0; x < 4; x++) {
		path[Lv] = name[x];
		go(Lv + 1);

		path[Lv] = 0;
	}
}

int main() {
	cin >> name;

	go(0);

	cout << cnt;

	return 0;
}