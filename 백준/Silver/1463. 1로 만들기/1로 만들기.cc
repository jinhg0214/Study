#include <iostream>

using namespace std;

int min_lev = 21e8;

void DFS(int level, int num) {
	if (level > min_lev) {
		return;
	}
	if (num == 1) {
		if (level < min_lev) {
			min_lev = level;
		}
		return;
	}
	
	if ((num % 3) == 0) {
		DFS(level + 1, num / 3);
	}
	if ((num % 2) == 0) {
		DFS(level + 1, num / 2);
	}
	DFS(level + 1, num - 1);
}

int main() {
	int N;
	cin >> N;

	DFS(0, N);

	cout << min_lev;

	return 0;
}