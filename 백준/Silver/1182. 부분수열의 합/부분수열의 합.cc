#include <iostream>

using namespace std;

int N, S;
int arr[21];
int cnt = 0;

void DFS(int level, int sum) {

	if (level == N) return; // 가지치기 조건 1. N을 모두 더한 경우
	if (sum + arr[level] == S) {
		cnt++;
	}

	DFS(level + 1, sum + arr[level]);
	DFS(level + 1, sum);

}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	DFS(0, 0);

	cout << cnt;

	return 0;
}