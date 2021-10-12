#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int card[41];
int path[41];
bool used[41];

int min_v = 21e8;
int res[41];

void DFS(int Lv, int start) {
	if (Lv == m) {
		int prod = 1;
		for (int i = 0; i < Lv; i++) {
			prod *= path[i];
		}
		if (min_v > prod) {
			min_v = prod;
			for (int i = 0; i < Lv; i++) {
				res[i] = path[i];
			}
		}
		return;
	}

	for (int x = start; x < n; x++) {
		if (used[x] == true) continue;
		used[x] = true;
		path[Lv] = card[x];
		DFS(Lv + 1, x);
		path[Lv] = 0;
		used[x] = false;
	}
}

int main() {
	freopen_s(new FILE*, "test.txt", "r", stdin);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}
	
	DFS(0, 0);

	sort(res, res + m);

	for (int i = 0; i < m; i++) {
		cout << res[i] << " ";
	}

	return 0;
}