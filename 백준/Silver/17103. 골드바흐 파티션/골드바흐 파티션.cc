#include <iostream>
#include <memory.h>

using namespace std;

bool grid[1000001];

void init_grid() {
	memset(grid, 1, sizeof(grid));
	grid[0] = 0;
	grid[1] = 0;

	for (int i = 2; i <= 1000; i++) { // sqrt(100,0000)
		if (grid[i] == false) continue; 
		for (int j = i*2; j <= 1000000; j = j + i) {
			grid[j] = false;
		}
	}
}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);

	int T, n;

	init_grid();

	cin >> T;
	while (T--) {
		cin >> n;
		int cnt = 0;
		for (int i = 2; i <= n/2; i++) {
			if (grid[i] == true && grid[n - i] == true) cnt++;
		}
		cout << cnt << '\n';
	}


	return 0;
}