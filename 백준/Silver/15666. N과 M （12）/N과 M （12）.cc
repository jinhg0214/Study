#include <iostream>
#include <algorithm>

#define MAX 9

using namespace std;

int N, M;
int path[MAX];
int tmp[MAX], arr[MAX], idx = 0;

void DFS(int level, int start) {
	if (level >= M) {
		for (int i = 0; i < level; i++) {
			printf("%d ", path[i]);
		}
		printf("\n");
		return;
	}
	for (int t = start; t <= idx; t++) {
		path[level] = arr[t];
		DFS(level + 1, t);
		path[level] = 0;
	}
}

int main() {
	// freopen_s(new FILE*, "sample_input.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp[i]);
	}
	sort(tmp, tmp+ N);
	arr[0] = tmp[0];

	for (int i = 1; i < N; i++) {
		if (tmp[i - 1] == tmp[i]) continue;
		arr[++idx] = tmp[i];
	}

	DFS(0, 0);

	return 0;
}