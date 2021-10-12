// 미로가 주어질 때 도착 할 수 있는지 여부 확인

/*
0,0부터 시작해서 네 방향으로 진입 시도.
이후 진입한 위치가 목표지점이라면 종료. -> 탈출 조건
아니라면 계속 시도 

1. 배열 범위 밖인가?
2. 이미 방문한 곳인가?
3. 방문할 수 없는 벽인가?

*/

#include <iostream>

using namespace std;

int map[4][4] = { 
	0,0,0,0,
	1,0,1,0,
	1,0,1,0,
	0,0,0,0
};

int visited[4][4] = { 1 }; // 0,0은 1로 체크
bool flag = false; // 도착시 확인용

int direct[4][2] = { -1,0, 1,0, 0,-1, 0,1 };

void abc(int y, int x) {

	if (y == 3 && x == 3) {
		flag = 1;
		return;
	}

	for (int t = 0; t < 4; t++) {
		int dy = y + direct[t][0];
		int dx = x + direct[t][1];

		// 1. 배열 범위 확인
		if (dy < 0 || dx < 0 || dy > 3 || dx > 3) continue;
		// 2. 재방문 확인
		if (visited[dy][dx] == 1) continue;
		// 3. 벽 확인
		if (map[dy][dx] == 1) continue;

		visited[dy][dx] = 1;
		abc(dy, dx);
		visited[dy][dx] = 0;
	}
}

int main() {

	abc(0, 0); // 시작 좌표값

	if (flag == true) {
		cout << "도착 가능";
	}
	else {
		cout << "도착 불가능";
	}

	return 0;
}

/*
#include <iostream>

#define N 4

using namespace std;

int directY[4] = {0,1,0,-1};
int directX[4] = {1,0,-1,0};
bool flag = false;

int map[N][N] = { // 0: 이동가능, 1: 벽
	0,0,0,0,
	1,0,1,0,
	1,0,1,0,
	0,0,0,0
};

int used[N][N];

void Route(int y, int x) {

	if (y == 3 && x == 3) {
		flag = true;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int dy = y + directY[i];
		int dx = x + directX[i];

		if (used[dy][dx] == 1) continue;
		if (dy < 0 || dx < 0 || dy > N - 1 || dx > N - 1) continue;
		if (map[dy][dx] == 1) continue;

		used[dy][dx] = 1;
		Route(dy, dx);
		used[dy][dx] = 0;
	}
}

int main() {
	
	Route(0, 0);

	cout << flag;

	return 0;
}
*/