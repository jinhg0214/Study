#include <iostream>
#include <string>
using namespace std;

int price[7] = { 15,20,44,22,55,16,45 };
string orderList;
int n;
int m;

char path[10];
int used[10];

int max_value = 0;

int calc() {
	int sum = 0;
	for (int i = 0; i < m; i++) {
		int idx = path[i] - 'a';
		sum += price[idx];
	}
	return sum;
}

void DFS(int Lv, int start) {

	if (Lv == m) {
		int result = calc();
		if (result % 10 == 0) {
			if (max_value < result) {
				max_value = result;
			}
		}
		return;
	}
	for (int x = start; x < orderList.length(); x++) {
		if (used[x] == 1) continue;
		used[x] = 1;
		path[Lv] = orderList[x];
		
		DFS(Lv + 1, x);

		path[Lv] = 0;
		used[x] = 0;
	}
}

int main() {
	// freopen_s(new FILE*, "test.txt", "r", stdin);

	cin >> orderList;
	cin >> n;

	m = orderList.length() - n; // n개 반려

	DFS(0, 0);

	cout << max_value;

	return 0;
}