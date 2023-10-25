#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V;
vector< vector<int> > map;
int visited[1001] = { 0 };

void DFS(int now) {
	cout << now << " ";

	// 현재 노드와 연결된 노드 찾기
	for (int i = 0; i < map[now].size(); i++) {
		int next = map[now][i];
		if (visited[next] == 1) continue;
		visited[next] = 1;
		DFS(next);
	}

}

void BFS(int start) {
	queue<int> qu;

	visited[V] = 1;
	qu.push(start);

	while (!qu.empty()) {
		int now = qu.front();
		qu.pop();

		cout << now << " ";

		for (int i = 0; i < map[now].size(); i++) {
			int next = map[now][i];
			if (visited[next] == 1) continue;
			visited[next] = 1;
			qu.push(next);
		}

	}


}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> N >> M >> V;

	map.resize(N + 1);

	while (M--) {
		int start, end;
		cin >> start >> end;
		map[start].push_back(end);
		map[end].push_back(start);
	}

	for (int i = 0; i < N + 1; i++) {
		sort(map[i].begin(), map[i].end());
	}
	
	
	
	visited[V] = 1;
	DFS(V);
	cout << "\n";

	fill(visited, visited + 1001, 0);

	BFS(V);

	return 0;
}