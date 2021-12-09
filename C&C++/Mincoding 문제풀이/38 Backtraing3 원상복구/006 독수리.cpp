/*
1번 독수리 : 0~2
2번 독수리 : 3~5
3번 독수리 : 1~4 
한 턴에 1>2>3> 순으로 식사
먹고나면 그 배열은 0이됨

한턴이 지나면 살아남은 먹이는 2배가 됨

먹은 먹이의 최대값 구하기
*/

#include <iostream>
#include <cstring>

using namespace std;

int prey[7]; // 먹이 크기
int backup[7];
int n; // 식사 회수


void Input() {
	for (int i = 0; i < 6; i++) {
		cin >> prey[i];
	}
	cin >> n;
}

void Hunt(int Lv, int sum) {

	if (Lv == 3) { // 한 턴에 3번 식사 가능
		return;
	}

	int now;
	// 첫번째 독수리: 0~2
	if (Lv == 0) {
		for (int x = 0; x <= 2; x++) {
			now = prey[x];
			prey[x] = 0;
			Hunt(Lv + 1, sum + now);
			prey[x] = now;
		}
	}
	// 두번째 독수리: 3~5
	else if (Lv == 1) {
		for (int x = 3; x <= 5; x++) {
			now = prey[x];
			prey[x] = 0;
			Hunt(Lv + 1, sum + now);
			prey[x] = now;
		}
	}
	// 세번째 독수리: 1~4
	else if (Lv == 2) {
		for (int x = 1; x <= 4; x++) {
			now = prey[x];
			prey[x] = 0;
			Hunt(Lv + 1, sum + now);
			prey[x] = now;
		}
	}
}

int main() {
	freopen_s(new FILE*, "test.txt", "r", stdin);

	Input();

	memcpy(backup, prey, sizeof(backup)); // 원본 복사해둠

	while (n--) {
		Hunt(0, 0);
		
		// 두배 
		for (int i = 0; i < 7; i++) {
			prey[i] = 2 * prey[i];
		}
	}
	



	return 0;
}