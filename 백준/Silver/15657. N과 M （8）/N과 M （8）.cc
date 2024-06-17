#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[8];
int path[8];

void DFS(int level, int start) {
	// if (level >= 2 && path[level - 2] > path[level - 1]) return;
	if (level == M) {
		for (int i = 0; i < level; i++) {
			printf("%d ", path[i]);
		}
		printf("\n");
		return;
	}

	for (int x = start; x < N; x++) {

		path[level] = arr[x];
		DFS(level + 1, x);
		path[level] = 0;

	}


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