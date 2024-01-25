#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> level;
int cnt = 0;

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N;
	level.resize(N);
	for (int i = 0; i < N; i++)
		cin >> level[i];

	// 맨 뒤 원소값과 그 앞 원소를 비교
	for (int i = N - 1; i >= 1; i--) {
		while (level[i - 1] >= level[i]) {
			level[i - 1]--;
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}