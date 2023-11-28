#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX 201

int N, K, S;
int map[MAX][MAX];
int visited[MAX][MAX];

struct Node{
	int y;
	int x;
	int num;
	int time;
};
int direct[4][2] = { 0,1,1,0,0,-1,-1,0 };

// 세균의 번호를 입력받아 그 세균을 증식시키는 BFS
void BFS() {
	queue<Node> qu;
	memset(visited, 0, sizeof(visited));

	// 3중 for문
	// 최대 1000 * 201 * 201 = 40,000,000. 10억이 대략 1초니까 OK
	for (int i = 1; i <= K; i++) { // 1번 바이러스부터 K번까지 차례로 큐에 넣음
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (map[y][x] == i) {
					qu.push({ y, x, i, 0 }); // 0초로 지정
					visited[y][x] = 1;
				}
			}
		}
	}

	// S초 까지 BFS를 돌린다 
	// 1~K까지 한번씩 다 돌아야 1초가 경과함
	
	int sec = 0;
	while (!qu.empty()) {
		Node now = qu.front();
		qu.pop();

		if (now.time == S) break;

		for (int t = 0; t < 4; t++) {
			int dy = direct[t][0] + now.y;
			int dx = direct[t][1] + now.x;

			if (dy < 0 || dx < 0 || dy >= N || dx >= N) continue; // 경계 처리
			if (map[dy][dx] != 0) continue; // 다른 세균
			if (visited[dy][dx] == 1) continue; // 이미 방문

			visited[dy][dx] = 1;
			map[dy][dx] = map[now.y][now.x];
			qu.push({ dy, dx, now.num, now.time + 1 });
		}
	}
}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> K;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
		}
	}

	int target_y, target_x;
	cin >> S >> target_y >> target_x;

	BFS();

	cout << map[target_y-1][target_x-1];

	return 0;
}