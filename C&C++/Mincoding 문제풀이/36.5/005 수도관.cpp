#include <iostream>

using namespace std;

int n;
int map[11][11];

int Max = 0;

void Input() {
	cin >> n;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> map[y][x];
		}
	}
}

void DFS(int Lv, int sum) {

	if (Lv == n) {
		if (sum > Max) {
			Max = sum;
		}
		return;
	}
	for (int x = 0; x < n; x++) {
		DFS(Lv + 1, sum * map[Lv][x]);
	}

}

int main() {
	// freopen_s(new FILE*, "test.txt", "r", stdin);
	Input();

	DFS(0, 1);
	
	cout << Max;

	return 0;
}