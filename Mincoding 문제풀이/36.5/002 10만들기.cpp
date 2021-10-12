#include <iostream>
#include <string>

using namespace std;

int cnt = 0;

void dfs(int Lv, int max , int sum) {

	if (sum > 10) return;
	if (Lv == max) {
		if (sum == 10) {
			cnt++;
		}
		return;
	}

	
	for (int x = 1; x <= 9; x++) {
		dfs(Lv + 1, max, sum + x);
	}

}

int main() {
	int n;
	cin >> n;
	dfs(0, n, 0);

	cout << cnt;

	return 0;
}