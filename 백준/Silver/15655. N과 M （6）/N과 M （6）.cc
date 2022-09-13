#include <iostream>
#include <algorithm>

#define MAX 9

using namespace std;

int N, M;
int arr[MAX];
int path[MAX];
bool visited[MAX];

void DFS(int level, int start){
	if (level == M) {
		for (int i = 0; i < level; i++) {
			printf("%d ", path[i]);
		}
		printf("\n");
		return;
	}
	for (int t = start; t < N; t++) {
		if (visited[t] == true)continue;

		visited[t] = 1;
		path[level] = arr[t];

		DFS(level + 1, t);

		visited[t] = 0;
		path[level] = 0;

	}

	return;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + N);

	DFS(0, 0);

	return 0;
}