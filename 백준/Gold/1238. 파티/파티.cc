#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 1005

int N, M, target;
vector<pair<int, int>> map[MAX];
int dist[MAX];
int max_cost = 0;

void dijkstra(int start, int target) {
	// 1. dist 배열 INF로 초기화
	for (int i = 1; i <= N; i++) {
		dist[i] = 21e8;
	}
	// 2. pq 선언 후 시작 노드 넣기
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });// 시작점과 코스트를 저장
	dist[start] = 0; // 시작 지점은 코스트 0

	while (!pq.empty()) {
		int curDist = -pq.top().first; // 음수로 저장해서 최소값을 뽑았으므로, 다시 양수화시킴
		int cur = pq.top().second; 
		pq.pop();

		for (int i = 0; i < map[cur].size(); i++) {
			int next = map[cur][i].first;
			int nextDist = map[cur][i].second;

			// 현재 노드의 이동거리와 다음 노드의 이동거리의 합이 저장된 값보다 작다면 교체
			if (curDist + nextDist < dist[next]) {
				dist[next] = curDist + nextDist;
				pq.push({-dist[next], next }); // 최소값을 뽑기 위해 음수화하여 저장
			}
		}
	}


}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> target;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		map[a].push_back({ b, c });
	}

	// 왕복 거리를 계산해야한다
	// 1번부터 N번까지 
	// i 에서 target으로 가는데 걸리는 cost를 계산하고
	// target 에서 i로 돌아오는데 걸리는 cost 를 계산하여 더한 뒤 최대값인지 확인 
	for (int i = 1; i <= N; i++) {
		int cur_cost = 0;
		dijkstra(i, target);
		cur_cost += dist[target];
		dijkstra(target, i);
		cur_cost += dist[i];

		max_cost = max(max_cost, cur_cost);
	}

	cout << max_cost;

	return 0;
}