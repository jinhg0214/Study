#include <iostream>
#define MAX 9

using namespace std;

int N, M;
int path[MAX];

void DFS(int level) {
	if (level >= M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", path[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 1; i <= N; i++) {
		path[level] = i;
		DFS(level + 1);
		path[level] = 0;
	}
}

int main() {
	scanf("%d %d", &N, &M);

	DFS(0);

	return 0;
}