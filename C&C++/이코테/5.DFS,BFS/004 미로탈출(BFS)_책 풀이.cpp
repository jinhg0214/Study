#include <iostream>
#include <queue>

using namespace std;

int N, M;
int map[205][205];

int direct[4][2] = { 0,1, 1,0, 0,-1, -1,0 };

void Input() {
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
		}
	}
	return;
}

int BFS(int y, int x) {
	// BFS start
	queue< pair<int, int> > qu;
	qu.push({ y,x });

	while (!qu.empty()) {
		int y = qu.front().first;
		int x = qu.front().second;
		qu.pop();

		for (int t = 0; t < 4; t++) {
			int dy = y + direct[t][0];
			int dx = x + direct[t][1];

			if (dy < 0 || dx < 0 || dy >= N || dx >= M) continue; // 경계처리
			if (map[dy][dx] == 0) continue; // 괴물

			// 첫 방문인 경우, 최단거리 기록하기
			if (map[dy][dx] == 1) {
				map[dy][dx] = map[y][x] + 1;
				qu.push({ dy,dx });
			}
		}
	}

	return map[N - 1][M - 1];
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	Input();

	cout << BFS(0, 0);

	return 0;
}