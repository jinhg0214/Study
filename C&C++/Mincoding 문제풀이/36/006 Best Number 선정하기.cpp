#include <iostream>

using namespace std;

int input[5];
int path[5];
bool used[5];

int min_v = 21e8;
int max_v = -21e8;

int calc() {
	return (path[0] * path[1]) - (path[2] * path[3]) + path[4];
}

void DFS(int Lv) {

	if (Lv == 5) {
		int result = calc();
		if (min_v > result) min_v = result;
		if (max_v < result) max_v = result;
		return;
	}
	for (int x = 0; x < 5; x++) {
		if (used[x] == true) continue;
		used[x] = true;
		path[Lv] = input[x];
		
		DFS(Lv + 1);

		path[Lv] = 0;
		used[x] = false;
	}
}

int main() {
	for (int i = 0; i < 5; i++) {
		cin >> input[i];
	}

	DFS(0);

	cout << max_v << endl << min_v;

	return 0;
}