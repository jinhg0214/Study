// DFS로 탐색

#include <iostream>

using namespace std;

int map[6][6] = {
	0,0,1,1,0,1,
	0,0,0,1,1,1,
	0,0,0,0,1,1,
	0,0,0,0,0,0,
	1,0,0,0,0,1,
};

int used[6];

void DFS(int now) {
	cout << now << " ";
	for (int x = 0; x < 6; x++) {
		if (map[now][x] == 1 && used[x] == 0) {
			used[x] = 1;
			DFS(x);
		}
	}
}

int main() {
	int n;

	cin >> n;

	used[n] = 1;
	DFS(n);

	return 0;
}