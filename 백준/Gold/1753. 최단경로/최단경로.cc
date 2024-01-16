#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX 20001
#define INF 21e8

int V, E, start;
int dist[MAX]; 
vector<pair<int, int>>map[MAX];


void dijkstra(int start) {
	for (int i = 1; i <= V; i++)
		dist[i] = INF;

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < map[cur].size(); i++) {
			int next = map[cur][i].first;
			int nCost = map[cur][i].second;

			if (dist[next] > cost + nCost) {
				dist[next] = cost + nCost;
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
		int a, b, c; cin >> a >> b >> c;
		map[a].push_back({ b, c });
	}

	
	dijkstra(start);

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF)
			cout << "INF" << endl;
		else
			cout << dist[i] << endl;
	}

}