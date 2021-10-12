// 한 술취한 아저씨가 위에서 아래로 내려온다
// 아저씨는 ↙↓↘ 세방향으로 이동 가능하다
// map[5][4]의 배열이 주어질 때
// 이 아저씨가 밟은 칸의 점수가 최대가 되는 때를 DFS로 구해라

/*
풀이 :
(0,0)만 DFS를 돌리면 안됨 
(0,0), (0,1), (0,2), (0,3) 총 4번 DFS를 돌려야 하는 문제


*/
#include <iostream>

using namespace std;

int map[5][4] = {
	3,2,4,1,
	0,1,0,5,
	2,0,3,0,
	5,4,0,2,
	2,5,0,3,
};

int max_sum = -21e8;


void abc(int now, int level, int sum) { // x좌표
	if (level == 5) {
		if (max_sum < sum) max_sum = sum;
		return;
	}

	for (int x = 0; x < 3; x++) {
		int direct[3] = { -1,0,1 };
		int dy = level;
		int dx = direct[x] + now;

		if (dx < 0 || dx >3) continue; // y는 안봐도 됨
		if (map[dy][dx] == 0) continue;

		abc(dx, level + 1, sum + map[dy][dx]);
	}

}

int main() {
	// 시작 지점은 (0,0)~(0,3)중 아무곳에서 스타트 가능
	for (int x = 0; x < 4; x++) {
		abc(x, 0, 0);  // now, level, sum
	}

	cout << max_sum;
		
	return 0;
}

/*
#include <iostream>

using namespace std;

int directY[3] = { 1,1,1 };
int directX[3] = { -1,0,1, };

int map[5][4] = {
	3,2,4,1,
	0,1,0,5,
	2,0,3,0,
	5,4,0,2,
	2,5,0,3,
};

int max_sum = -21e8;

void Drunken(int y, int x, int Lv, int sum) {

	if (Lv == 5) {
		if (max_sum < sum) {
			max_sum = sum;
		}
		return;
	}

	for (int i = 0; i < 3; i++) {
		int dy = y + directY[i];
		int dx = x + directX[i];

		if (dy < 0 || dx < 0 || dy > 5 || dx > 4) continue;

		Drunken(dy, dx, Lv + 1, sum + map[y][x]);
	}
}

int main() {

	for (int x = 0; x < 4; x++) {
		Drunken(0, x, 0, 0); // 시작 지점은 (0,0)~(0,3)중 아무곳에서 스타트 가능
	}

	cout << max_sum;
		
	return 0;
}
*/