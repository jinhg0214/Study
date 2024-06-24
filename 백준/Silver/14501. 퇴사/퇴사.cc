#include <iostream>

using namespace std;

int N;
int T[16], P[16];
int sum = 0, res = 0;

void DFS(int level, int sum) {
	if (level > N) return; // 가지치기 조건1 : 퇴사일을 넘어가는 경우
	if (level == N) {
		if (sum > res) {
			res = sum;
		}
		return;
	}
	DFS(level + 1, sum); // 선택 안하고 다음날로 넘어가는 경우
	DFS(level + T[level], sum + P[level]); // 오늘 일을 수주하는 경우

	return;
}

int main() {
	// freopen_s(new FILE*, "sample_input.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> T[i] >> P[i];
	}

	DFS(0, 0);

	cout << res;

	return 0;
}