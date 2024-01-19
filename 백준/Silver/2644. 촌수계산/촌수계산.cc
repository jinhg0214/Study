#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, x, y, m;
int family_tree[101][101];
int visited[101];

struct node {
	int num;
	int level;
};


int BFS(int x, int y) {
	queue<node> qu;
	qu.push({ x, 0 });
	visited[x] = 1;

	while (!qu.empty()) {
		node now = qu.front();
		qu.pop();

		if (now.num == y) {
			return now.level;
		}

		// 번호는 1번부터 N번까지있음
		for (int i = 1; i <= n; i++) {			
			if (visited[i] == 1) continue;
			if (family_tree[now.num][i] == 0) continue;
			visited[now.num] = 1;
			qu.push({i,now.level + 1});
		}
	}

	return -1;
}


int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> n;
	cin >> x >> y;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int a, b; 
		cin >> a >> b;
		family_tree[a][b] = 1;
		family_tree[b][a] = 1;
	}

	cout << BFS(x, y) ;

	return 0;
}

/*
사람수 int n (1 ≤ n ≤ 100)
구할 촌수 x, y
부모 자식 관계 m개

최대 100 * 100이므로 2차원 배열로 해도 문제없을듯함
*/