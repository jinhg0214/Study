#include <iostream>

using namespace std;

int n;
int day[101];
int cost[101];

int max_v = 0;

void DFS(int Lv, int sum) {

	if (Lv >= n) {
		if (max_v < sum) {
			max_v = sum;
		}
		return;
	}

	// 수주하면 Day[Lv] 만큼 시간이 경과하고, 금액이 증가한다
	DFS(Lv + day[Lv], sum + cost[Lv]);
	DFS(Lv + 1, sum);

}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> day[i] >> cost[i];
	}

	DFS(0, 0);

	cout << max_v;

	return 0;
}