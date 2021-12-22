#include <iostream>
#include <queue>

using namespace std;

int N, M;
int map[1005][1005];
int visited[1005][1005];
int ans = 0;

int direct[4][2] = { 0,-1, -1,0, 0, 1, 1, 0 };

void Input() {
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
		}
	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	Input();

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			// 만약 구멍이 뚫려있으면 BFS 시작
			if (map[y][x] == 0) {	
				queue< pair<int, int> > qu;
				qu.push({ y, x });
				visited[y][x] = 1;

				while (!qu.empty()) {
					pair<int, int> now = qu.front();
					qu.pop();

					for(int t=0; t<4; t++){
						int dy = now.first + direct[t][0];
						int dx = now.second + direct[t][1];

						if (dy < 0 || dx < 0 || dy >= N || dx >= M) continue; // 경계처리
						if (map[dy][dx] == 1) continue; // 벽이라면 패스

						visited[dy][dx] = 1;
						map[dy][dx] = 1; //
						qu.push({ dy, dx });
					}
				}

				ans++;
			}
		}
	}

	cout << ans;

	return 0;
}