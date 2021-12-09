#include <iostream>
#include <queue>

using namespace std;

char name[11] = "ABCDEFGHIJ";
int n;
int map[51][51];

struct node {
	int start, end;
	int cost;
};

bool operator<(node back, node front) {
	return front.cost > back.cost;
}

priority_queue<node> q;

void Init() {
	cin >> n;

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> map[y][x];
			q.push({ y, x, map[y][x] });
		}
	}

}

int main() {
	freopen_s(new FILE*, "test.txt", "r", stdin);

	Init();

	for (int i = 0; i < 3; i++) {
		node now = q.top();
		q.pop();

		cout << name[now.start] << "-" << name[now.end] << " " << now.cost << endl;
	}

	return 0;
}