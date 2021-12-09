#include <iostream>

using namespace std;

int map[6][6] = {
	0,0,0,0,1,0,
	1,0,1,0,0,1,
	1,0,0,1,0,0,
	1,1,0,0,0,0,
	0,1,0,1,0,1,
	0,0,1,1,0,0,
};

int queue[100];
int head = 0, tail = 1;
int used[6];

int main() {
	int n;
	cin >> n;
	used[n] = 1;
	queue[0] = n;

	while (head != tail) {
		int now = queue[head++];

		cout << now << endl;

		for (int x = 0; x < 6; x++) {
			if (map[now][x] == 1 && used[x] == 0) {
				used[x] = 1;
				queue[tail++] = x;
			}
		}
	}


	return 0;
}