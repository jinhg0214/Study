#include <bits/stdc++.h>

using namespace std;

int N, M, V;
vector<vector<int>> edge;
bool visited[1001];

void input() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> M >> V;

	edge.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int start, end;
		cin >> start >> end;
		edge[start].push_back(end);
		edge[end].push_back(start);
	}

	// 엣지가 여러개인 경우 노드가 작은것부터 방문
	for (int i = 0; i <= N; i++) {
		sort(edge[i].begin(), edge[i].end());
	}
}

void dfs(int level, int cur) {
	// 들어오면서 방문 처리 후 출력
	visited[cur] = 1;
	cout << cur << ' ';

	for (int i = 0; i < edge[cur].size(); i++) {
		int next = edge[cur][i];

		if (visited[next] == 1) continue;
		dfs(level + 1, next);
	}
}

void bfs() {
	memset(visited, 0, sizeof(visited));

	queue<int> qu;
	visited[V] = 1;
	qu.push(V);

	while (!qu.empty()) {
		int now = qu.front();
		qu.pop();

		cout << now << ' ';

		for (int i = 0; i < edge[now].size(); i++) {
			int next = edge[now][i];
			if (visited[next] == 1) continue;
			visited[next] = 1;
			qu.push(next);
		}
	}

	return;
}

int main() {
	input();

	dfs(0, V);

	cout << '\n';

	bfs();

	return 0;
}