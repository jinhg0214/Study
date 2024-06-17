#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> v;
vector<int> path;

void run(int level, int start) {
	if (level == M) {
		for (int e : path) {
			cout << e << ' ';
		} cout << '\n';
		return;
	}
	int last_num = 0;
	for (int i = start; i < N; i++) {
		if (last_num == v[i]) continue;
		path.push_back(v[i]);
		last_num = v[i];

		run(level + 1, i);

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

	run(0, 0);

	return 0;
}