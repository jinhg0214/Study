#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> num;
vector<int> oper(4);
int min_val = 21e8, max_val = -21e8;

void DFS(int level, int sum) {
	if (level == N - 1) {
		min_val = min(min_val, sum);
		max_val = max(max_val, sum);
		return;
	}
	// '+'
	if (oper[0] > 0) {
		oper[0]--;
		DFS(level + 1, sum + num[level + 1]);
		oper[0]++;
	}
	// '-'
	if (oper[1] > 0) {
		oper[1]--;
		DFS(level + 1, sum - num[level + 1]);
		oper[1]++;
	}
	// '*'
	if (oper[2] > 0) {
		oper[2]--;
		DFS(level + 1, sum * num[level + 1]);
		oper[2]++;
	}
	// '/'
	if (oper[3] > 0) {
		oper[3]--;
		DFS(level + 1, sum / num[level + 1]);
		oper[3]++;
	}

	return;
}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> N;
	num.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> oper[i];
	}

	DFS(0, num[0]);

	cout << max_val << endl << min_val;

	return 0;
}