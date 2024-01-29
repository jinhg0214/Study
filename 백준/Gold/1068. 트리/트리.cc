#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[51]; // 각 노드의 부모 노드의 정보를 가지는 벡터. 트리를 직접 구현하지 않음
bool visited[51];
int root, k, leaf = 0;

void dfs(int node) {

	// 탈출 조건 1. 이미 방문한 노드
	if (visited[node]) return;

	visited[node] = true;

	// 리프 노드인경우
	if (tree[node].size() == 0) {
		leaf++;
		return;
	}
	// 혹은 자식 개수가 1개인데, 그 자식이 삭제할 노드인 경우
	else if (tree[node].size() == 1 && tree[node][0] == k) {
		leaf++;
		return;
	}

	// 자식들 탐색
	for (int i = 0; i < tree[node].size(); i++) {
		// 삭제할 노드라면 패스
		if (tree[node][i] == k) continue;
		// 아니라면 더 들어가본다
		dfs(tree[node][i]);
	}
}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int node;  cin >> node;
		if (node == -1) {
			root = i;
		}
		else {
			tree[node].push_back(i); // 노드의 부모 노드를 저장
		}
	}

	cin >> k; // 지울 노드 입력
	// 루트 지우는 경우 다날라감
	if (k == root) {
		cout << 0;
		return 0;
	}

	dfs(root); // k 를 지우면 k와 연결된 모든 노드 정보들도 삭제된다
	cout << leaf;
	return 0;
}