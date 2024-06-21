#include <iostream>

using namespace std;

int N;
int map[11][11];
int visited[11];
int min_cost = 21e8;

// 첫 출발 도시, 현재 도시, 몇번째 경로, 현재까지 비용을 받음
void run(int start, int now, int level, int cost) {
	if (cost > min_cost) return; // 가지치기 : 이미 최소 비용을 초과한 경우 더이상 보지 않음
	if (level == N-1) { // 모든 도시를 방문한 경우
		
		// 집으로 돌아갈 경로가 없다면 리턴
		if (map[now][start] == 0) return;

		cost += map[now][start]; // 마지막으로 원래의 도시까지 돌아오는 코스트 계산

		min_cost = min(min_cost, cost);
		return;
	}

	for (int i = 0; i < N; i++) {
		if (map[now][i] == 0) continue; 
		if (visited[i] == 1) continue;

		visited[i] = 1;
		run(start, i, level + 1, cost + map[now][i]);
		visited[i] = 0;
	}
}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	
	for (int i = 0; i < N; i++) {
		visited[i] = 1;
		run(i, i, 0, 0);
		visited[i] = 0;
	}
	
	cout << min_cost;

	return 0;
}
