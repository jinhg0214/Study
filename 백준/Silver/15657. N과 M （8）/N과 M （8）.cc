#include <iostream>
#include <algorithm>
#define MAX 9
using namespace std;

int N, M;
int path[MAX];
int arr[MAX];

void Input() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + N);
}

void DFS(int level, int start) {
	if (level >= M) {
		for (int i = 0; i < level; i++) {
			printf("%d ", path[i]);
		}
		printf("\n");
		return;
	}

	for (int t = start; t < N; t++) {
		path[level] = arr[t];
		DFS(level+1, t);
		path[level] = 0;
	}
	return;
}

int main() {
	// freopen_s(new FILE*, "sample_input.txt", "r", stdin);
	
	Input();

	DFS(0, 0);

	return 0;
}