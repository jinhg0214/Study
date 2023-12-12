#include <iostream>
#include <queue>

using namespace std;

#define MAX 501

int n, m;
int map[MAX][MAX]; // 1 ~ n개 사용
int visited[MAX];

struct node {
	int num;
	int level;
};

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> n >> m;

	// m개 입력
	for (int i = 0; i < m; i++) {
		int start, end;
		cin >> start >> end;
		map[start][end] = 1; // 양방향 노드
		map[end][start] = 1;
	}

	visited[1] = 1; // 상근이
	queue<node> qu;
	qu.push({ 1, 0 });

	while (!qu.empty()) {
		node now = qu.front();
		qu.pop();

		for (int i = 2; i <= n; i++) {
			if (now.level >= 2) continue; // 친구의 친구까지만 살펴봄
			if (visited[i] == 1) continue; // 이미 초대한 경우
			if (map[now.num][i] == 0) continue; // 친구가 아닌 경우

			visited[i] = 1;
			qu.push({ i, now.level + 1 });
		}
	}

	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		if (visited[i] == 1) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}