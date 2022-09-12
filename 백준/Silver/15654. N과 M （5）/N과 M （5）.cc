#include <iostream>
#include <algorithm>

#define MAX 9

using namespace std;

int N, M;
int arr[MAX];
int path[MAX];
bool visited[MAX];

void DFS(int level) {
	if (level == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", path[i]);
		}
		printf("\n");
		return;
	}

	for (int t = 0; t < N; t++) {
		if (visited[t] == true) continue;

		visited[t] = true;
		path[level] = arr[t];

		DFS(level + 1);

		visited[t] = false;
		path[level] = 0;
	}
}

int main() {
	// freopen_s(new FILE*, "sample_input.txt", "r", stdin);
	
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + N);

	DFS(0);

	return 0;
}