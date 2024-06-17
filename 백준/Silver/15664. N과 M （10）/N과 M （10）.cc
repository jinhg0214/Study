#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[9];
int path[9];
int used[9];

void DFS(int level, int start) {
	if (level == M) {
		for (int i = 0; i < level; i++) {
			cout << path[i] << " ";
		}
		cout << endl;
		return;
	}

	int last_num = 0;
	for (int x = start; x < N; x++) {
		if (used[x] == 1) continue;
		if (last_num == arr[x]) continue;
		used[x] = 1;
		path[level] = arr[x];
		last_num = arr[x];

		DFS(level + 1, x);

		used[x] = 0;
		path[level] = 0;

	}

}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	DFS(0, 0);

	return 0;
}