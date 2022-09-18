/* 중복 처리 두가지 방법이있음.
1. prev 변수를 두어 path에 아예 넣지 않는 방법
2. 벡터를 두고 일단 생성한 path는 다 넣고 set<> 을 이용하여 중복을 제거하는 방법
여기서는 prev를 사용하였음
*/
#include <iostream>
#include <algorithm>

#define MAX 9

using namespace std;

int N, M;
int path[MAX];
int visited[MAX];
int arr[MAX];

void DFS(int level, int start) {
	if (level >= M) {
		for (int i = 0; i < level; i++) {
			cout << path[i] << " ";
		}
		cout << '\n';
		return;
	}
	int prev = 0;
	for (int t = start; t < N; t++) {
		if (visited[t] == true) continue;
		
		if (prev == arr[t]) continue; // 중복된 수열이라면 거름

		visited[t] = true;
		path[level] = arr[t];
		prev = arr[t];
		DFS(level + 1, t);

		path[level] = 0;
		visited[t] = false;
	}
}

int main() {
	// freopen_s(new FILE*, "sample_input.txt", "r", stdin);
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);

	DFS(0, 0);


	return 0;
}