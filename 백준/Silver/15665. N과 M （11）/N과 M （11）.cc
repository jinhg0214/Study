#include <iostream>
#include <algorithm>
#define MAX 9

using namespace std;

int N, M;
int path[MAX];
int arr[MAX];
int idx = 0;

void DFS(int level) {
	if (level >= M) {
		for (int i = 0; i < level; i++) {
			printf("%d ", path[i]);
		}
		printf("\n");
		return;
	}

	for (int t = 0; t <= idx; t++) {
		path[level] = arr[t];
		DFS(level + 1);
		path[level] = 0;
	}
	return;
}

int main() {
	// freopen_s(new FILE *, "sample_input.txt", "r", stdin);
	scanf("%d %d", &N, &M);

	int tmp[MAX] = { 0 };
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp[i]);
	}
	sort(tmp, tmp + N);

	
	arr[0] = tmp[0];
	for (int i = 1; i < N; i++) {
		if (tmp[i] == tmp[i - 1]) continue; // 이미 같은값이 들어있다면 패스
		arr[++idx] = tmp[i];
	}

	DFS(0);

	return 0;
}