// n을 입력받고
// n개의 숫자를 입력받는다
// 4개의 커스텀 사칙연산을 통해 
// 결과값이 100이 되는 경우의 수를 구하기

/*
 * Lv: n, Br: 4인 문제
 * 누적값 acc를 통해 백트래킹한다 
 */

#include <iostream>

using namespace std;

int n;
int arr[11];
int cnt = 0;

void Input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

void BF(int Lv, int acc) {

	if (Lv == n) {
		if (acc == 100) cnt++;
		return;
	}

	if (Lv == 0) { acc = arr[0]; }
	// acc !! arr[Lv+1]
	BF(Lv + 1, (acc - arr[Lv + 1]) * (acc + arr[Lv + 1]));

	// #
	BF(Lv + 1, acc>arr[Lv+1] ? acc : arr[Lv+1]);

	// $
	BF(Lv + 1, (acc*acc) - (arr[Lv+1]*arr[Lv+1]));

	// &
	BF(Lv + 1, (acc + arr[Lv + 1])* (acc + arr[Lv + 1]));
}

int main() {
	freopen_s(new FILE*, "test.txt", "r", stdin);

	Input();

	BF(0, 0);

	cout << cnt;

	return 0;
}