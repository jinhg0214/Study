#include <iostream>

using namespace std;

int N, M;
int map[1005][1005];
int ans = 0;

void Input() {
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
		}
	}
}

int dfs(int dy, int dx) {
	if (dy < 0 || dx < 0 || dy >= N || dx >= M) return 0; // 경계처리
	if (map[dy][dx] == 1) return 0; // 이미 방문한곳

	// 방문한적이 없다면 방문처리하고, 4방향으로 DFS 호출
	map[dy][dx] = 1;
	dfs(dy, dx - 1);
	dfs(dy - 1, dx);
	dfs(dy, dx + 1);
	dfs(dy + 1, dx);
	return 1;

}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	Input();

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (dfs(y, x) == 1) ans++;
		}
	}
	
	cout << ans;

	return 0;
}