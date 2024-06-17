#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> v;
int used[10];
vector<int> path;

void run(int level) {
	if (level >= 2 && path[level - 2] > path[level - 1]) return;
	if (level == M) {
		for (int e : path) {
			cout << e << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		if (used[i] == 1) continue;
		used[i] = 1;
		path.push_back(v[i]);

		run(level + 1);

		used[i] = 0;
		path.pop_back();
	}
}

int main() {
	cin >> N >> M;

	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	
	run(0);

	return 0;
}