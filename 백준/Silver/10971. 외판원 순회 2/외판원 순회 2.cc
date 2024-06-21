#include <iostream>
#include <vector>

using namespace std;

int N;

int map[11][11];
int path[11];
int visited[11];
int res = 21e8;

void Input() {
	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
		}
	}
}

void path_find(int start, int y, int sum,int cnt) {
	// 이미 최소값을 초과한 경우 패스
	if (sum > res) return;
	// 모든 도시를 들렀고, 다시 시작점으로 돌아온 경우.
	if (cnt == N && start == y) {
		if (sum < res) {
			res = sum;
		}
		return;
	}

	for (int x = 0; x < N; x++) {
		if (map[y][x] == 0) continue;
		if (visited[x] == 1) continue;

		visited[x] = 1;
		path_find(start, x, sum + map[y][x], cnt + 1);
		visited[x] = 0;
	}

}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	Input();
	
	for (int i = 0; i < N; i++) {
		path_find(i, i, 0, 0);
	}

	cout << res;

	return 0;
}