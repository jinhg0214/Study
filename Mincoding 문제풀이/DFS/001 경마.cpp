// 1 ~ 9번 까지의 말
// 1~4등의 말 번호의 합이 10 이하인 경우의 수는 몇가지인가

/*
순열 문제 -> 한번 뽑으면 더이상 뽑지 않음 : Used 배열 사용
가지는 9개, Lv은 4까지
*/

#include <iostream>

using namespace std;

int cnt;
int used[10];

void abc(int level, int sum) {

	if (sum > 10) return; // 백트래킹
	if (level == 4) {
		cnt++;
		return;
	}

	for (int x = 1; x <= 9; x++) {
		if (used[x] == 1) continue;
		used[x] = 1;
		abc(level + 1, sum + x);
		used[x] = 0;
	}
}

int main() {

	abc(0, 0); // Level, Sum

	cout << cnt;

	return 0;
}

/*

#include <iostream>

using namespace std;

int path[4];
int used[10];
int cnt = 0;

void DFS(int Lv) {

	if (Lv == 4) {
		int sum = 0;
		for (int i = 0; i < 4; i++) {
			sum += path[i];
		}
		if (sum <= 10) {
			cnt++;
		}

		return;
	}

	for (int x = 1; x <= 9; x++) {
		if (used[x] == 1) continue;
		used[x] = 1;
		path[Lv] = x;
		DFS(Lv + 1);
		used[x] = 0;
		path[Lv] = 0;
	}

}

int main() {

	DFS(0);

	cout << cnt;

	return 0;
}

*/