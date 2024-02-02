#include <iostream>
#include <queue>

using namespace std;

int N, M;
int map[102][102];
int visited[102][102] = { 0 };
int direct[4][2] = { 1,0, 0,1, -1,0, 0,-1 };

struct node {
	int y;
	int x;
	int cost;
};

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> N >> M;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			char ch;
			cin >> ch;
			map[y][x] = (ch - '0');
		}
	}

	queue<node> qu;
	int res = 1;
	visited[0][0] = 1;
	qu.push({ 0,0,0 });

	while (!qu.empty()) {
		node now = qu.front();
		qu.pop();

		if (now.y == N - 1 && now.x == M - 1) {
			res = now.cost + 1; // 마지막칸 포함
		}

		for (int t = 0; t < 4; t++) {
			int dy = direct[t][0] + now.y;
			int dx = direct[t][1] + now.x;

			if (dy < 0 || dx < 0 || dy > N || dx > M) continue;
			if (map[dy][dx] == 0) continue;
			if (visited[dy][dx] == 1) continue;
			

			visited[dy][dx] = 1;
			qu.push({ dy, dx, now.cost+1 });

		}
	}

	cout << res;

	return 0;
}