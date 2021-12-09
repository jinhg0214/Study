#include <iostream>
#include <string>

using namespace std;

int N; // 해야할 일 개수
double percentage[17][17]; // 확률
int visited[17];
double max_percent;

void Input() {
	// init
	memset(percentage, 0, sizeof(percentage));
	memset(visited, 0, sizeof(visited));
	max_percent = 0.0;

	// input
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp;
			cin >> tmp;
			percentage[i][j] = tmp / 100.0;
		}
	}
}

void DFS(int Lv, double res) {

	// 가지치기 1: 현재 최대 확률보다 "작거나 같다면" 더이상 확인하지 않는다.
	// 어짜피 현재확률에 1이하의 값이 곱해지기 때문
	if (res <= max_percent) return;
	

	// 바닥조건 : 마지막 Lv
	if (Lv == N) {
		// 현재 확률과 비교
		if (max_percent < res) {
			max_percent = res;
		}
		return;
	}

	// DFS
	for (int i = 0; i < N; i++) {
		if (visited[i] == 1) continue;
		visited[i] = 1;
		DFS(Lv + 1, res * percentage[Lv][i]);
		visited[i] = 0;
	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	int T, i = 1;
	cin >> T;
	while (T--) {
		Input();
	
		DFS(0, 1.0);

		printf("#%d %.6lf\n", i++, max_percent * 100);
	}

	return 0;
}