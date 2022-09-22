#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

vector<int> a[1001]; // 인접리스트를 이용
bool check[1001]; // 정점에 방문했는지를 체크하는 배열

void dfs(int node) {

	check[node] = true; // 첫 방문
	printf("%d ", node);

	for (int i = 0; i < a[node].size(); i++) { // 저장된 인접리스트의 원소들에 대해 각각 검사
		int next = a[node][i];

		if (check[next] == false) {
			dfs(next);
		}
	}

}

void bfs(int start) {
	queue<int> q; // bfs는 큐 이용

	memset(check, false, sizeof(check));

	check[start] = true; 
	q.push(start); // 첫 노드를 큐에 추가

	while (!q.empty()) { // 큐가 빌때까지 반복
		int node = q.front(); // 큐의 처음 원소 검사
		q.pop();

		printf("%d ", node);

		for (int i = 0; i < a[node].size(); i++) {
			int next = a[node][i];
			if (check[next] == false) {
				check[next] = true; // 큐에 넣을때, 방문한것으로 취급!
				q.push(next);
			}
		}
	}

}

int main() {

	int n, m, start;

	scanf("%d %d %d", &n, &m, &start);

	for (int i = 0; i < m; i++) {
		int u, v;

		scanf("%d %d", &u, &v);

		a[u].push_back(v); // (u,v)
		a[v].push_back(u); // (v,u)
	}

	// 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문 
	for (int i = 1; i <= n; i++) {
		sort(a[i].begin(), a[i].end());
	}

	dfs(start);
	printf("\n");
	bfs(start);
	printf("\n");
	return 0;
}