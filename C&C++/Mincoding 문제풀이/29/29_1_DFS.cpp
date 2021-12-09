#include <iostream>

using namespace std;

int n;
int map[101][101];

void DFS(int now) {

	cout << now << " ";

	for (int x = 0; x < n; x++) {
		if (map[now][x] == 1) {
			DFS(x);
		}
	}
}

int main() {

	cin >> n;

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> map[y][x];
		}
	}

	DFS(0);

	return 0;
}