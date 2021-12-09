// BFS
#include <iostream>

using namespace std;

int map[6][6] = {
	0,1,0,0,1,0,
	0,0,1,0,0,1,
	0,0,0,1,0,0,
};

int queue[100];
int head = 0, tail = 0;

int main() {
	int n;

	cin >> n;

	queue[0] = n;
	tail++;

	while (head != tail) {
		int now = queue[head];
		head++;

		cout << now << " ";

		for (int x = 0; x < 6; x++) {
			if (map[now][x] == 1) {
				queue[tail] = x;
				tail++;
			}
		}
	}

}