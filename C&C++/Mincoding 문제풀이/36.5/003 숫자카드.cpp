#include <iostream>

using namespace std;

int card[4];
int used[4];
int path[4];
int cnt = 0;

void DFS(int Lv) {

	if (Lv == 4) {
		int res = path[0]*1000 + path[1]*100 + path[2]*10 + path[3];
		if (res > 3129) cnt++;
		return;
	}

	for (int x = 0; x < 4; x++) {
		if (used[x] == 1) continue;
		used[x] = 1;
		path[Lv] = card[x];
		DFS(Lv + 1);
		path[Lv] = 0;
		used[x] = 0;
	}

}

int main() {
	for (int i = 0; i < 4; i++) {
		cin >> card[i];
	}

	DFS(0);

	cout << cnt;

	return 0;
}