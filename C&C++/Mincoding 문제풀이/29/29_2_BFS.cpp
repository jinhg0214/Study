// 최소 이동거리 -> BFS 이용

#include <iostream>

using namespace std;

int map[6][6]{
	0,0,1,0,1,1,
	1,0,0,1,0,0,
	0,0,0,0,1,0,
	1,0,0,0,0,0,
	1,0,0,0,0,0,
	0,0,0,0,0,0,
};

struct node {
	int index;
	int level;
};

node queue[100];
int head = 0;
int tail = 1;
int used[6];

void BFS(int start, int end) {

	used[start - 1] = 1;
	queue[0].index = start - 1;
	queue[0].level = 0;

	while (head != tail) {
		node now = queue[head++];

		if (now.index == end-1) {
			cout << now.level;
			return;
		}

		for (int x = 0; x < 6; x++) {
			if (map[now.index][x] == 1 && used[x] == 0) {
				used[x] = 1;

				queue[tail].index = x;
				queue[tail].level = now.level + 1;
				tail++;
			}
		}
	}

	cout << 0;
}

int main() {
	int start, end;
	
	cin >> start >> end;

	BFS(start, end);

	return 0;
}