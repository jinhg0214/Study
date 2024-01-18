#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 10001
#define INF 21e8

int N, M, X;
vector<pair<int, int>> map[MAX];
int dist[MAX];
int result[MAX];


// 시작지점부터 x까지의 최단거리를 찾는 다익스트라 함수
void dijkstra(int start) {
	for (int i = 0; i <= N; i++) {
		dist[i] = 21e8;
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty()) {
		int curDist = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < map[cur].size(); i++) {
			int nextDist = map[cur][i].first;
			int next = map[cur][i].second;

			if (curDist + nextDist < dist[next]) {
				dist[next] = curDist + nextDist;
				pq.push({ dist[next], next });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;
		map[start].push_back({ cost, end });
	}

	// 각 마을에서 X까지 가는 다익스트라 계산
	for (int i = 1; i <= N; i++) {
		dijkstra(i);
		result[i] = dist[X];
	}
	
	// 파티장 X에서 각 마을로 돌아오는 다익스트라 계산
	dijkstra(X);

	for (int i = 1; i <= N; i++) {
		result[i] += dist[i];
	}

	int max_cost = 0;
	for (int i = 1; i <= N; i++) {
		max_cost = max(max_cost, result[i]);
	}
	cout << max_cost;

	return 0;
}