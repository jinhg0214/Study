#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
vector<long long int> result;

void dfs(int level, long long int num) {
	result.push_back(num);
	if (level >= 10) return;

	dfs(level + 1, num * 10 + arr[level]);
	dfs(level + 1, num);
}

int main() {
	int n;
	cin >> n;

	if (n > 1023) {
		cout << -1;
		return 0;
	}

	dfs(0, 0);

	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()), result.end());

	cout << result[n-1];

	return 0;
}