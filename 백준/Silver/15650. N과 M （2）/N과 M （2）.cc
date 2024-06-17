#include <bits/stdc++.h>

using namespace std;

int N, M;
int used[10];
int arr[10];

void run(int level, int start) {
	if (level == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = start; i <= N; i++) {
		if (used[i] == 1) continue;

		used[i] = 1; 
		arr[level] = i;

		run(level+1, i);

		used[i] = 0;
	}
}

int main() {
	cin >> N >> M;

	run(0, 1);

	return 0;
}