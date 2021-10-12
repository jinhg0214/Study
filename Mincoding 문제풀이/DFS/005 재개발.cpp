// 특정 좌표를 재개발하면
// 그 주위 상하좌우까지 땅값이 변동한다
// (x * 3) % 10 만큼 값이 변동할 때
// 총 세번 개발 할 때 전체 땅값이 가장 큰 경우 구하기

// 특정 좌표를 재개발하면
// 그 주위 상하좌우까지 땅값이 변동한다
// (x * 3) % 10 만큼 값이 변동할 때
// 총 세번 개발 할 때 전체 땅값이 가장 큰 경우 구하기

#include <iostream>
#include <cstring> // memcpy 이용을 위해

using namespace std;

int map[3][3] = {
	4,1,7,
	8,9,1,
	1,5,2,
};

int Max = 0;

void digging(int y, int x) {
	int direct[5][2] = { 0,0, -1,0, 1,0, 0,-1, 0,1 };
	for (int t = 0; t < 5; t++) {
		int dy = y + direct[t][0];
		int dx = x + direct[t][1];

		if (dy < 0 || dx < 0 || dy > 2 || dx > 2) continue;

		map[dy][dx] = (map[dy][dx] * 3) % 10;
	}
}

int getsum() {
	int sum = 0;
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			sum += map[y][x];
		}
	}
	return sum;
}

void abc(int level) {
	
	int backup[3][3]; // 원래대로 돌려놓기 위해 미리 백업해놓음

	if (level == 3) {
		int result = getsum();
		if (result > Max) Max = result;
		return;
	}

	memcpy(backup, map, sizeof(map));

	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			digging(y, x);
			abc(level + 1);
			memcpy(map, backup, sizeof(backup));
		}
	}
}

int main() {

	abc(0);

	cout << Max;

	return 0;
}

/*
#include <iostream>

using namespace std;

int direct[4][2] = {
	1,0,
	-1,0,
	0,1,
	0,-1,
};

int map[3][3] = {
	4,1,7,
	8,9,1,
	1,5,2,
};

int visited[3][3];

int max_value = 0;

void Redevelop(int y, int x, int Lv) {

	if (Lv == 2) {
		// 현재 전체 땅 값 계산
		int sum = 0;
		for (int y = 0; y < 3; y++) {
			for (int x = 0; x < 3; x++) {
				sum += map[y][x];
			}
		}
		if (max_value < sum) {
			max_value = sum;
		}

		return;
	}

	// 땅값 변동
	map[y][x] = (map[y][x] * 3) % 10;

	for(int t = 0; t < 4; t++) {
		int dy = y + direct[t][0];
		int dx = x + direct[t][1];

		if (dy < 0 || dx < 0 || dy > 2 || dx > 2) continue;

		map[dy][dx] = (map[dy][dx] * 3) % 10;
	}

	// dfs
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			visited[y][x]++;
			Redevelop(y, x, Lv + 1);
			visited[y][x]--;
		}
	}
}

int main() {

	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			visited[y][x]++;
			Redevelop(y, x, 0);
			visited[y][x]--;
		}
	}

	cout << max_value;

	return 0;
}
*/