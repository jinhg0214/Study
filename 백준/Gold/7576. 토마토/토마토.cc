#include <iostream>
#include <queue>

using namespace std;

int N, M;
int map[1005][1005];

struct Node {
	int y;
	int x;
	int level;
};

int direct[4][2] = { 0,1,1,0,0,-1,-1,0 };

void Input() {
	scanf("%d %d", &N, &M);

	for (int y = 0; y < M; y++) {
		for (int x = 0; x < N; x++) {
			scanf("%d", &map[y][x]);
		}
	}
	return;
}

void BFS() {
	queue< Node > qu;

	// 1. 익은 토마토를 찾아 큐에 넣는다
	for (int y = 0; y < M; y++) {
		for (int x = 0; x < N; x++) {
			if (map[y][x] == 1) {
				qu.push({ y,x,1 });
			}
		}
	}

	// 2. BFS 시작
	while (!qu.empty()) {
		Node now = qu.front();
		qu.pop();

		for (int t = 0; t < 4; t++) {
			int dy = now.y + direct[t][0];
			int dx = now.x + direct[t][1];

			if (dy <0 || dx <0 || dy >= M || dx >= N) continue; // 경계처리
			if (map[dy][dx] != 0) continue; // 빈공간이 아닐 경우

			map[dy][dx] = now.level + 1; // 값을 넣어주고 큐에 다시 추가한다
			qu.push({ dy,dx,now.level + 1 });
		}
	}
}

int main() {
	// freopen_s(new FILE*, "sample_input.txt", "r", stdin);
	Input();

	BFS();

	int answer = -1;
	for (int y = 0; y < M; y++) {
		for (int x = 0; x < N; x++) {
			if (map[y][x] == 0) {
				answer = -1;
				printf("%d", answer);
				return 0;
			}
			if (map[y][x] != 0 && map[y][x] > answer) {
				answer = map[y][x];
			}
		}
	}
	printf("%d", answer-1);

	return 0;
}