#include <iostream>

using namespace std;

char card[3];
char path[3];
bool used[3];

void DFS(int Lv) {
	if (Lv == 3) {
		for (int i = 0; i < Lv; i++) {
			cout << path[i];
		}
		cout << endl;
		return;
	}

	for (int x = 0; x < 3; x++) {
		if (used[x] != 0) continue;
		used[x] = 1;
		path[Lv] = card[x];
		DFS(Lv + 1);
		path[Lv] = 0;
		used[x] = 0;
		
	}
}

int main() {

	for (int i = 0; i < 3; i++) {
		cin >> card[i];
	}

	DFS(0);

	return 0;
}