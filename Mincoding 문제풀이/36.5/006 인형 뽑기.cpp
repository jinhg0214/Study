#include <iostream>

using namespace std;

int n, k;
char map[1001][1001];

int direct[2][5][2] = { 
	{ -1,0, 0,0, 0,-1, 0,1, 1,0 },
	{ -1,-1, 0,0, -1,1, 1,1, 1,-1 }
};

void Input() {
	cin >> n >> k;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> map[y][x];
		}
	}
}

void Crane(int y, int x, int type) {

	for (int t = 0; t < 5; t++) {
		int dy = y + direct[type - 1][t][0];
		int dx = x + direct[type - 1][t][1];

		if (dy < 0 || dx < 0 || dy >= n || dx >= n) continue;

		cout << map[dy][dx];
	}
	cout << endl;
}

int main() {
	// freopen_s(new FILE*, "test.txt", "r", stdin);
	Input();

	while (k--) {
		int type, y, x;
		cin >> y >> x >> type;

		Crane(y, x, type);
	}

	return 0;
}