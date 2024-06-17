#include <bits/stdc++.h>

using namespace std;

int N, M;
int path[10];

void run(int level) {
	if (level >= 2 && path[level - 2] > path[level - 1]) return;
	if (level == M) {
		for (int i = 0; i < M; i++) {
			cout << path[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) {
		path[level] = i;
		run(level + 1);
	}
}

int main() {
	cin >> N >> M;

	run(0);

	return 0;
}