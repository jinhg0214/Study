#include <iostream>

using namespace std;

int money;
int coin[3] = { 10,40,60 };
int used[3];
int min_cnt = 999;
int cnt = 0;

void DFS(int sum) {

	if (sum > money) return;
	if (sum == money) {
		if (min_cnt > cnt) min_cnt = cnt;
		return;
	}

	for (int x = 0; x < 3; x++) {
		cnt++;
		DFS(sum + coin[x]);
		cnt--;
		
	}

}

int main() {
	cin >> money;

	DFS(0);

	cout << min_cnt;

	return 0;
}