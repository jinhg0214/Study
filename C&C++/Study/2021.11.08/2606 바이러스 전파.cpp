/*
https://www.acmicpc.net/problem/2606


한 컴퓨터가 바이러스에 걸리면, 그 컴퓨터와 네트워크상에 연결되어있는 모든 컴퓨터는 바이러스에 걸린다
전체 바이러스에 걸리는 컴퓨터는 몇대인지 찾는 문제

풀이) 그래프에서 연결된 노드들의 개수를 찾는 문제
- DFS, BFS 그래프 탐색 아무거나 가능
- DFS이용. used배열을 이용해 방문한 노드는 1로 체크. 

*/

#include <iostream>

#define MAX 101

using namespace std;

int N, M;
int map[MAX][MAX];
int used[MAX];

int ans = 0;

void DFS(int now) {
	// 노드는 1번부터 시작
	for (int x = 1; x <= MAX; x++) {
		if (map[now][x] == 1 && used[x] == 0) {
			used[x] = 1;
			ans++;
			DFS(x);
		}
	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int start, end;
		cin >> start >> end;

		// 양방향 간선임
		map[start][end] = 1;
		map[end][start] = 1;
	}

	// 1번부터 바이러스 시작
	used[1] = 1;
	DFS(1);

	cout << ans;

	return 0;
}