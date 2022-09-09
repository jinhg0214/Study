#include <iostream>

#define MAX 9

using namespace std;

int N, M;
int path[MAX];
int visited[MAX];

void DFS(int level, int num) {
	// M개를 선택한 경우 선택한 수들을 출력한다
	if (level >= M) {
		for (int i = 0; i < M; i++) {
			cout << path[i] << " ";
		}
		cout << endl;
		return;
	}
	// 1~N 중에 어떤걸 선택할 것인지
	for(int i=num; i<=N; i++){
		if (visited[i] == 1) continue; // 이미 선택했었던 수라면 패스

		visited[i] = 1;
		path[level] = i;


		DFS(level + 1, i);

		visited[i] = 0;
		path[level] = 0;
	}

}

int main() {
	scanf("%d %d", &N, &M);

	DFS(0, 1);

	return 0;
}