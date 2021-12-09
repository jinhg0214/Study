#include <iostream>

using namespace std;

char name[9] = "RKFCBICM";
int map[8][8];


void DFS(int now) {

	cout << name[now];
	for (int x = 0; x < 8; x++) {
		if (map[now][x] == 0) continue;
		DFS(x);
	}

}

int main() {
	// freopen_s(new FILE*, "test.txt", "r", stdin);

	cin >> name;

	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			cin >> map[y][x];
		}
	}

	DFS(0);

	return 0;
}