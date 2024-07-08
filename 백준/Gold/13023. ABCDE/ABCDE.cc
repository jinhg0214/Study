#include <iostream>
#include <vector>

using namespace std;

int N, M;

vector<vector<int>> map;
int visited[2001];
bool result = false;

void dfs(int level, int cur) {
	if (result == true) return;
	if (level == 4) {
		result = true;
		return;
	}

	visited[cur] = true;

	// 해당 원소 중 하나 선택
	for (int i = 0; i < map[cur].size(); i++) {
		int next = map[cur][i];
		
		if (visited[next] == 1) continue;

		visited[next] = 1;
		dfs(level + 1, next);
		visited[next] = 0;

	}
	visited[cur] = false;
}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> N >> M;
	map.resize(N);

	for (int i = 0; i < M; i++) {
		int start, end;
		cin >> start >> end;

		map[start].push_back(end);
		map[end].push_back(start); // 양방향 연결해둠
	}

	for (int i = 0; i < N; i++) {
		dfs(0, i);
	}
	

	cout << result;
	return 0;
}
