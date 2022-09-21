#include <iostream>
#include <queue>

using namespace std;

int N, M;
int map[101][101];
int visited[101][101];

int direct[4][2] = { 0,1, 1,0, -1,0, 0,-1 };

struct node {
	int y;
	int x;
	int level;
};

void Input() {
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			scanf("%1d", &map[y][x]);
		}
	}
}

int main() {
	// freopen_s(new FILE*, "test.txt", "r", stdin);
	Input();

	queue< node > qu;
	visited[0][0] = 1;

	qu.push({ 0,0,0 } );
	
	while (!qu.empty()) {
		node now = qu.front();
		qu.pop();

		if (now.y == N - 1 && now.x == M - 1) {
			cout << now.level+1;
			break;
		}

		for (int t = 0; t < 4; t++) {
			int dy = now.y + direct[t][0];
			int dx = now.x + direct[t][1];

			if (dy < 0 || dx < 0 || dy >= N || dx >= M) continue; // 경계처리
			if (map[dy][dx] == 0) continue; // 이동불가
			if (visited[dy][dx] == 1) continue; // 이미 방문

			visited[dy][dx] = 1;
			qu.push({ dy, dx, now.level + 1 } );
		}

	}
	

	return 0;
}