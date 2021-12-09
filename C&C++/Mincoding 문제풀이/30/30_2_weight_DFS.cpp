// DFS로 탐색

#include <iostream>

using namespace std;

int map[6][6] = {
	0,0,1,0,2,0,
	5,0,3,0,0,0,
	0,0,0,0,0,7,
	2,0,0,0,8,0,
	0,0,9,0,0,0,
	4,0,0,7,0,0,
};

int used[6];

void DFS(int now, int sum) {
	cout << now << " " << sum << endl;

	for (int x = 0; x < 6; x++) {
		if (map[now][x] != 0 && used[x] == 0) {
			used[x] = 1;
			sum += map[now][x];
			DFS(x, sum);
		}
	}
}

int main() {
	int n;

	cin >> n;

	used[n] = 1;

	DFS(n, 0);

	return 0;
}