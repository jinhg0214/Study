#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector< vector<int> > map;
int visited[101] = { 0 };
int cnt = 0;

void dfs(int now) {
	cnt++;
	for (int x = 0; x < map[now].size(); x++) {
		int next = map[now][x];
		if (visited[next] == 1) continue;
		visited[next] = 1;
		dfs(next);
	}
}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	
	cin >> N >> M;
	map.resize(N + 1);

	while (M--) {
		int start, end;
		cin >> start >> end;
		map[start].push_back(end);
		map[end].push_back(start);
	}

	visited[1] = 1;
	dfs(1);

	cout << cnt - 1; // 1번 컴퓨터 제외

}