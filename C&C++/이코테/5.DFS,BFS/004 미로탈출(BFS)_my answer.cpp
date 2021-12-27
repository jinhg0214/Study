// visited 배열을 사용해 방문 체크한 버전

#include <iostream>
#include <queue>

using namespace std;

int map[205][205];
int visited[205][205];
int N, M;

int direct[4][2] = { 0,1, 1,0, 0,-1, -1,0 };

struct node {
	int y;
	int x;
	int lev;
};

void Input() {
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
		}
	}
	return;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	Input();

	// BFS start
	queue<node> qu;
	qu.push({ 0,0,0 });
	visited[0][0] = 1;

	while (!qu.empty()) {
		node now = qu.front();
		qu.pop();

		if (now.y == N - 1 && now.x == M - 1) {
			cout << now.lev;
			break;
		}

		for (int t = 0; t < 4; t++) {
			int dy = now.y + direct[t][0];
			int dx = now.x + direct[t][1];

			if (dy < 0 || dx < 0 || dy >= N || dx >= M) continue; // 경계처리
			if (map[dy][dx] = 0) continue; // 괴물

			
			visited[dy][dx] = 1;
			qu.push({ dy,dx, now.lev + 1 });
		}
	}
	return 0;
}