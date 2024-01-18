#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 20001
#define INF 21e8

int V, E, start;
vector<pair<int, int>> v[MAX];
int dist[MAX];

void dijkstra(int start) {
	for (int i = 0; i <= V; i++) {
		dist[i] = INF;
	}

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start }); // 거리 0인 시작노드 추가
	dist[start] = 0;

	while (!pq.empty()) {
		int curDist = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		// 현재 노드와 연결된 노드들 검색
		for (int i = 0; i < v[cur].size(); i++) {
			int nextDist = v[cur][i].first;
			int next = v[cur][i].second;

			if (curDist + nextDist < dist[next]) {
				dist[next] = curDist + nextDist;
				pq.push({ -dist[next], next });
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> V >> E >> start;

	for (int i = 0; i < E; i++) {
		int start, end, cost; 
		cin >> start >> end >> cost;

		v[start].push_back({ cost, end });
	}

	dijkstra(start);

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) {
			cout << "INF" << endl;
		}
		else {
			cout << dist[i] << endl;
		}
	}

	return 0;
}