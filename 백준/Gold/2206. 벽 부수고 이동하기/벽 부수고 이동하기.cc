#include <iostream>
#include <queue>

using namespace std;

#define MAX 1001

int N, M;
int map[MAX][MAX];
int visited[MAX][MAX][2]; //3차원 배열 [y][x][벽 부순 여부]
int direct[4][2] = { 0,1,1,0,0,-1,-1,0 };

struct Node {
	int y;
	int x;
	int floor;
};

// 디버그용 출력 함수
void debug_print(int y, int x, int floor) {
	cout << "=======================================" << endl;

	printf("Now : (%d, %d), Level : %d\n", y, x, floor);
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cout << visited[y][x][floor] << " ";
		}
		cout << endl;
	}

}

int BFS() {
	queue<Node> qu;
	visited[0][0][0] = 1; // (0,0)에서 벽을 부수지 않은 층에서 출발
	qu.push({ 0,0,0 });

	while (!qu.empty()) {
		Node now = qu.front();
		qu.pop();

		// debug_print(now.y, now.x, now.floor);

		if (now.y == N - 1 && now.x == M - 1) {
			return visited[now.y][now.x][now.floor];
		}

		for (int t = 0; t < 4; t++) {
			int dy = direct[t][0] + now.y;
			int dx = direct[t][1] + now.x;

			if (dy < 0 || dx < 0 || dy >= N || dx >= M) continue; // 경계처리
			if (visited[dy][dx][now.floor] != 0) continue; // 이미 방문한곳이라면 패스

			//
			// 통과 가능한곳
			if (map[dy][dx] == 0) {
				// 기존 BFS와 똑같이 처리해준다
				visited[dy][dx][now.floor] = visited[now.y][now.x][now.floor] + 1; // 현재 visited값에 +1해서 저장해준다
				qu.push({ dy, dx, now.floor }); // 같은 층에서 계속 논다
			}
			// 벽이지만 한번 부술 수 있는 경우
			else if (map[dy][dx] == 1 && now.floor == 0) {
				// 윗층으로 올려보낸다
				visited[dy][dx][now.floor + 1] = visited[now.y][now.x][now.floor] + 1;
				qu.push({ dy, dx, now.floor + 1 });
			}
		}
	}
	return -1;
}

int main() {
	
	// 1. 입력받기
	// freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		string tmp; cin >> tmp;
		for (int x = 0; x < tmp.size(); x++) {
			map[y][x] = tmp[x] - '0';
		}
	}

	// 2. BFS
	int ret = BFS();
	if (ret == -1) {
		cout << -1;
	}
	else {
		cout << ret;
	}

	return 0;
}