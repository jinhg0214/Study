#include <iostream>
#include <vector>

using namespace std;

int N, root, dnode, leaf = 0;
vector<int> tree[51];
bool visited[51];

void dfs(int node) {
	// 탈출 조건 1. 이미 방문한 노드인 경우
	if (visited[node] == true) return;

	visited[node] = true;

	// 탈출 조건 2. 리프 노드인경우
	if (tree[node].size() == 0) {
		leaf++;
		return;
	}
	// 탈출 조건 3. 자식이 1개인 노드인데, 그 자식이 삭제할 노드일 경우 리프노드가 된다
	else if (tree[node].size() == 1 && tree[node][0] == dnode) {
		leaf++;
		return;
	}

	// 그 외의 경우는 DFS 탐색
	for (int i = 0; i < tree[node].size(); i++) {
		if (tree[node][i] == dnode) continue;
		dfs(tree[node][i]);
	}
}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int node;  cin >> node;
		if (node == -1) 
			root = i;
		else
			tree[node].push_back(i); // i번째 노드의 부모 노드가 주어짐 
	}
	cin >> dnode;
	if (dnode == root) {
		cout << 0;
		return 0;
	}


	dfs(root);

	cout << leaf;

	return 0;
}