#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[10];
int path[10];
bool visited[10];

void dfs(int level) {
	if (level == M) {
		for (int i = 0; i < M; i++) {
			cout << path[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visited[i] == true) continue;
		
		visited[i] = true;
		path[level] = arr[i];
		
		dfs(level + 1);

		visited[i] = false;
		path[level] = 0;

	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr+N);

	dfs(0);

	return 0;
}