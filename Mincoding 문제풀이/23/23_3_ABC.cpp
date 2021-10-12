// ABC
// n개의 초콜릿
// 연속으로 같은 초콜릿 선텍 불가능
// 총 가지수 출력하기

//LV : n, br : 3

#include <iostream>

using namespace std;

char path[10];
char name[5] = { "ABC" };
int cnt = 0;
int n;

void go(int Lv) {

	// 가지치기 조건1.3개 연속으로 같은 초콜릿인경우
	if (path[0] != '\0' && path[Lv - 2] == path[Lv - 1] && path[Lv - 3] == path[Lv - 2])return;

	if (Lv == n) {
		cnt++;
		return;
	}

	for (int x = 0; x < 3; x++) {
		path[Lv] = name[x];
		go(Lv + 1);

		path[Lv] = 0;
	}
}

int main() {

	cin >> n;

	go(0);

	cout << cnt;

	return 0;
}