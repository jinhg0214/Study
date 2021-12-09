#include <iostream>
#include <cstring>

using namespace std;

int n;
int map[5][5];
int backup[5][5];
int max_value = 0;

void Input() {
	cin >> n;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> map[y][x];
		}
	}
}

int Calc() {
	int res = 1;
	for (int x = 0; x < n; x++) {
		int tmp = 0;
		for (int y = 0; y < n; y++) {
			tmp += map[y][x];
		}
		res *= tmp;
	}
	return res;
}

// x번째 줄 Rotate Right
void RotateLine(int y) {
	int tmp = map[y][n - 1];
	for (int i = n-1; i > 0; i--) {
		map[y][i] = map[y][i - 1];
	}
	map[y][0] = tmp;
}

void DFS(int Lv) {

	if (Lv == 3) {
		int res = Calc();
		if (max_value < res) max_value = res;
		return;
	}
	
	memcpy(backup, map, sizeof(backup)); // 백업 떠놓기
	
	for (int y = 0; y < n; y++) {
		// 원상복구 후 돌리고, DFS
		memcpy(map, backup, sizeof(backup));
		RotateLine(y);
		DFS(Lv + 1);
	}

}

int main() {
	// freopen_s(new FILE*, "test.txt", "r", stdin);
	Input();

	DFS(0);

	cout << max_value <<"점";

	return 0;
}