#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector< vector<int> > map;
int visited[501];

void DFS(int level, int now) {
	if (level >= 2) {
		return;
	}

	for (int i = 0; i < map[now].size(); i++) {
		int next = map[now][i];
		visited[next] = 1;
		DFS(level + 1, next);
	}
}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> n >> m;
	map.resize(n+1);

	for (int i = 0; i < m; i++) {
		int start, end;
		cin >> start >> end;
		map[start].push_back(end);
		map[end].push_back(start);
	}

	visited[1] = 1;
	DFS(0, 1);

	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		if (visited[i] == 1)
			cnt++;
	}

	cout << cnt;
	return 0;
}