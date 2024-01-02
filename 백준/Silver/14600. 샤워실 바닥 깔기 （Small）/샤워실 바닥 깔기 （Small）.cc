#include <iostream>

using namespace std;

int block[4][2][2] = {
	{1,1,
	0,1},
	{0,1,
	1,1},
	{1,0,
	1,1},
	{1,1,
	1,0}
};

int k;
int x, y;
int map[5][5];
int num = 0;

// 주어진 정사각형이 모두 비어있는지 체크하는 함수
// 배수구(-1)가 있으면, false 리턴함
bool check(int sz, int x, int y) {
	for (int i = x; i < x + sz; i++) {
		for (int j = y; j < y + sz; j++) {
			if (map[i][j] != 0) 
				return false;
		}
	}
	return true;
}

// 분할정복
// x, y, sz를 받아 4부분으로 쪼개서 가능한지 확인한다
void sol(int x, int y, int sz) {
	num++;
	int s = sz / 2;

	// 왼쪽 아래 (1,1)~(2,2)
	if (check(s, x, y)) { map[x + s - 1][y + s - 1] = num; }
	// 오른쪽 아래 (1,3)~(2,4)
	if (check(s, x, y + s)) { map[x + s - 1][y + s] = num; }
	// 왼쪽 위 (3,1)~(4,2)
	if (check(s, x + s, y)) { map[x + s][y + s - 1] = num; }
	// 오른쪽 위 (3,3)~(4,4)
	if (check(s, x + s, y + s)) { map[x + s][y + s] = num; }

	if (sz == 2) return; // 최소 단계. 더이상 나누어지지 않는다
	sol(x, y, s);
	sol(x + s, y, s);
	sol(x, y + s, s);
	sol(x + s, y + s, s);

}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> k;
	cin >> x >> y;

	map[y-1][x-1] = -1;

	sol(0, 0, 1 << k); // (1,1)에서 시작, 2^K칸

	for (int i = (1 << k) - 1; i >= 0; i--) {
		for (int j = 0; j < (1 << k); j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}