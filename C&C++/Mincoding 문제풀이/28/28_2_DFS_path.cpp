#include <iostream>

using namespace std;

int n;
int map[10][10];
int path[3];

void DFS(int now, int lv) {
	// 들어올 때 넣어줌
	path[lv] = now;

	if (lv == 2) {
		for (int i = 0; i <= lv; i++){
			cout << path[i] << " ";
		}
		cout << endl;
		
		return;
	}

	for (int x = 0; x < n; x++) {
		if (map[now][x] == 1) {
			DFS(x, lv+1);
		}
	}
}

int main() {
	//freopen_s(new FILE*, "test.txt", "r", stdin);

	cin >> n;

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> map[y][x];
		}
	}

	DFS(0,0);

	return 0;
}