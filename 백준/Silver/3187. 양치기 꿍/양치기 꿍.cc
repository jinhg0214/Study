#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

#define MAX 251

int R, C;
char map[MAX][MAX];
int visited[MAX][MAX];
int direct[4][2] = { 0,1,1,0,0,-1,-1,0 };
int result_wolf = 0, result_sheep = 0;


void BFS(int starty, int startx) {
	queue<pair<int, int>> qu;
	qu.push({ starty, startx });
	visited[starty][startx] = 1;

	int wolf = 0, sheep = 0;

	while (!qu.empty()) {
		pair<int, int> now = qu.front();
		qu.pop();

		if (map[now.first][now.second] == 'v') {
			wolf++;
			map[now.first][now.second] = '.';
		}
		else if (map[now.first][now.second] == 'k') {
			sheep++;
			map[now.first][now.second] = '.';
		}

		for (int t = 0; t < 4; t++) {
			int dy = direct[t][0] + now.first;
			int dx = direct[t][1] + now.second;

			if (dy < 0 || dx < 0 || dy >= R || dx >= C) continue; // 경계 밖
			if (map[dy][dx] == '#') continue; // 울타리
			if (visited[dy][dx] == 1) continue;

			visited[dy][dx] = 1;
			qu.push({ dy,dx });
		}
	}

	if (wolf < sheep) {
		result_sheep += sheep;
	}
	else {
		result_wolf += wolf;
	}
}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> R >> C;
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			cin >> map[y][x];
		}
	}

	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if (map[y][x] != '#' && visited[y][x] == 0)
				BFS(y, x);
		}
	}

	cout << result_sheep << " " << result_wolf << endl;


	return 0;
}