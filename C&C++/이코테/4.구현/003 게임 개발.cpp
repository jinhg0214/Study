#include <iostream>

using namespace std;

int N, M;
int x, y, direction;

int map[51][51];
int visited[51][51];

int direct[4][2] = { -1,0, 0,1, 1,0, 0,-1 };

// 왼쪽으로 회전하는 함수
void turn_left() {
	direction -= 1;
	if (direction == -1) direction = 3;
}

int main(void) {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	// Input
	cin >> N >> M;
	cin >> x >> y >> direction;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
		}
	}
	visited[y][x] = 1;

	int cnt = 1;
	int turn_time = 0;

	while (true) {
		// 1. 왼쪽으로 회전한다
		turn_left();
	
		int dy = y + direct[direction][0];
		int dx = x + direct[direction][1];

		// 2. 다음 이동할 곳이 방문하지 않은 곳이고, 바다가 아닌 경우
		if (visited[dy][dx] == 0 && map[dy][dx] != 1) {
			visited[dy][dx] = 1; // 방문한다
			y = dy;
			x = dx;
			cnt += 1;
			turn_time = 0; // 초기화 해준다
			continue;
		}

		// 3. 회전한 이후 가보지 않은 칸이 없거나 바다인 경우
		else {
			turn_time += 1;
		}

		// 4. 네 방향 모두 갈 수 없는 경우
		if (turn_time == 4) {
			int dy = y - direct[direction][0];
			int dx = x - direct[direction][1];

			// 뒤로갈 수 있다면 이동
			if (map[dy][dx] == 0) {
				y = dy;
				x = dx;
			}

			// 뒤가 막혀있는 경우
			else break;
			turn_time = 0;
		}
	}

	cout << cnt;

	return 0;
}