#include <iostream>
#include <queue>

using namespace std;

int n;
int map[501][501];

struct node {
	int start, end;
	int cost;
};

bool operator<(node back, node front) {
	// 우선순위 1. 간선의 비용
	if (front.cost < back.cost) return true;
	if (front.cost > back.cost) return false;

	// 우선순위 2. 출발 간선
	if (front.start < back.start) return true;
	if (front.start > back.start) return false;

	// 우선순위 3. 도착 간선
	return front.end < back.end;
}

priority_queue<node> q;

void Init() {
	cin >> n;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> map[y][x];
			// a-c나 c-a는 같으므로 한번만 넣어준다
			if (map[y][x] != 0 && map[y][x] != -1 && map[x][y]) {
				q.push({ y, x, map[y][x] });
			}
		}
	}
}

int main() {
	freopen_s(new FILE*, "test.txt", "r", stdin);
	Init();

	// 10회 올림
	for (int i = 0; i <= 10; i++) {
		node now = q.top();
		q.pop();

		// 2배로 올린 노드를 다시 큐에 집어넣음
		map[now.start][now.end] = now.cost * 2;
		q.push({ now.start, now.end, now.cost * 2 });

		if (i == 10) {
			cout << now.cost * 2 << "만원";
		}
	}

	return 0;
}