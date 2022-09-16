#include <iostream>
#include <algorithm>

#define MAX 9

using namespace std;

int N, M;
int path[MAX];
int arr[MAX];
int visited[MAX];

void DFS(int level) {
	if (level >= M) {
		for (int i = 0; i < level; i++) {
			cout << path[i] << " ";
		}
		cout << '\n';
		return;
	}
	int last_arr = 0;
	for (int t = 0; t < N; t++) {
		if (visited[t] == true) continue; // 이미 사용한 배열이라면 패스
		if (last_arr == arr[t]) continue; // 이전 방문 기록과 같다면 패스
		visited[t] = true;
		path[level] = arr[t];
		last_arr = arr[t];
		DFS(level + 1);
		path[level] = 0;
		visited[t] = false;

	}
}

int main() {
	// freopen_s(new FILE*, "sample_input.txt", "r", stdin);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	DFS(0);

	return 0;
}