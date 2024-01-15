#include <iostream>

using namespace std;

int strength = 500;
int N, K;
int weight[9];
int used[9];
int result = 0;

void DFS(int level, int str) {
	if (str < 500) return;
	if (level == N) {
		result++;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (used[i] == 1) continue;
		used[i] = 1;
		DFS(level + 1, str + weight[i] - K);
		used[i] = 0;
	}

}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> weight[i];
	}

	DFS(0, strength);

	cout << result;

	return 0;
}