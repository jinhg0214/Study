// 0,0에서 n-1,n-1까지 도달 가능여부 확인

#include <iostream>

using namespace std;

int n;
int map[16][16];
int used[16][16];

int direct[4][2] = { -1,0,0,-1,1,0,0,1 };

struct node {
	int y;
	int x;
	int level;
};

node queue[1000];
int head = 0, tail = 0;

int main() {
	//Input();
	cin >> n;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> map[y][x];
		}
	}

	// Init();
	queue[0] = { 0,0,0 };
	tail = 1;
	bool flag = false;
	used[0][0] = 1;

	while (head != tail) {
		node now = queue[head++];
		
		for (int t = 0; t < 4; t++) {
			int dy = now.y + direct[t][0];
			int dx = now.x + direct[t][1];

			if (dy < 0 || dx < 0 || dy >= n || dx >= n) continue; // 경계 처리
			if (map[dy][dx] == 1) continue; // 막힌길
			if (used[dy][dx] == 1) continue; // 이미 방문한 곳
			used[dy][dx] = 1;

			queue[tail++] = { dy,dx,now.level + 1 };

			if (dy == n - 1 && dx == n - 1) {
				flag = true;
				break;
			}
		}
	}
	
	if (flag) {
		cout << "가능";
	}
	else {
		cout << "불가능";
	}

	return 0;
}