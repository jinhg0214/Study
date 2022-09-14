#include <iostream>
#include <algorithm>
#define MAX 9 
using namespace std;

int N, M;
int path[MAX];
int arr[MAX];

void DFS(int level) {
	if (level >= M) {
		for (int i = 0; i < level; i++) {
			printf("%d ", path[i]);
		}
		printf("\n");
		return;
	}

	for (int t = 0; t < N; t++) {
		path[level] = arr[t];
		DFS(level + 1);
		path[level] = 0;

	}

	return;
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