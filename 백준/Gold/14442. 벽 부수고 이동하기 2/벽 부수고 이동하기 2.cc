#include <iostream>
#include <queue>

using namespace std;

#define MAX 1001

int N, M, K;
int map[MAX][MAX];
int visited[MAX][MAX][11];

struct Node {
	int y;
	int x;
	int w;
};

int direct[4][2] = { 0,1,1,0,0,-1,-1,0 };

void debug_print(int y, int x, int w) {
	printf("===================================\nNow : (%d, %d) Level : %d\n", y, x, w);
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			printf("%d ", visited[y][x][w]);
		}
		printf("\n");
	}
}


int BFS() {
	queue<Node> qu;
	qu.push({ 0,0,0 });
	visited[0][0][0] = 1;

	while (!qu.empty()) {
		Node now = qu.front();
		qu.pop();

		// debug_print(now.y, now.x, now.w);

		if (now.y == N - 1 && now.x == M - 1) {
			return visited[now.y][now.x][now.w];
		}

		for (int t = 0; t < 4; t++) {
			int dy = direct[t][0] + now.y;
			int dx = direct[t][1] + now.x;

			if (dy < 0 || dx < 0 || dy >= N || dx >= M) continue;
			if (visited[dy][dx][now.w] != 0) continue;

			if (map[dy][dx] == 0) {
				visited[dy][dx][now.w] = visited[now.y][now.x][now.w] + 1;
				qu.push({ dy, dx, now.w });
			}
			else if (map[dy][dx] == 1 && now.w < K && visited[dy][dx][now.w + 1] == 0) {
				visited[dy][dx][now.w + 1] = visited[now.y][now.x][now.w] + 1;
				qu.push({ dy, dx, now.w + 1 });
			}
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> N >> M >> K;
	for (int y = 0; y < N; y++) {
		string tmp; cin >> tmp;
		for (int x = 0; x < tmp.size(); x++) {
			map[y][x] = tmp[x] - '0';
		}
	}

	int ret = BFS();

	cout << ret;

	return 0;
}