#include <bits/stdc++.h>

using namespace std;

int N, M;
int used[10];
int path[10];

void run(int level) {
	if (level > M) {
		for (int i = 1; i <= M; i++) {
			cout << path[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (used[i] == 1) continue;
		used[i] = 1;
		path[level] = i;
		run(level + 1);
		used[i] = 0;
	}
}

int main() {
	cin >> N >> M;

	run(1);

	return 0;
}