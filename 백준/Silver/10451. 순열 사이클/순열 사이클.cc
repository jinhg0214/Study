#include <iostream>

using namespace std;

int T, N;
int arr[1005];
int visited[1005] = { 0 };

void DFS(int now) {
	// cout << arr[now] << " ";

	int next = arr[now];

	if (visited[next] == 1) return;
	visited[next] = 1;
	DFS(next);

	return;
}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> T;

	while (T--) {
		cin >> N;

		fill_n(arr, N + 1, 0);
		fill_n(visited, N + 1, 0);

		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
		}

		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			if (visited[i] == 1) continue;
			visited[i] = 1;
			DFS(i);
			cnt++;
		}
		cout << cnt << "\n";
	}


	return 0;
}