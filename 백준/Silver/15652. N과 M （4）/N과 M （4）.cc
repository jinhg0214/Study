#include <iostream>

#define MAX 9

using namespace std;

int N, M;
int path[MAX];

void DFS(int level, int start) {
	if (level == M) {
		for (int i = 0; i < level; i++) {
			printf("%d ", path[i]);
		}
		printf("\n");
		return;
	}

	for (int t = start; t <= N; t++) {
		path[level] = t;
		DFS(level + 1, t);
		path[level] = 0;
	}

}

int main() {
	scanf("%d %d", &N, &M);

	DFS(0, 1);

	return 0;
}