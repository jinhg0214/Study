#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> energy_ball;
int result = 0;

void dfs(int level, int sum) {
	if (level == N - 2) {
		result = max(result, sum);
		return;
	}
	// 첫 번째와 마지막 에너지 구슬은 고를 수 없다
	for (int i = 1; i < energy_ball.size()-1; i++) {
		int cur_energy = energy_ball[i - 1] * energy_ball[i + 1];
		
		// i번째 에너지 구슬을 제거
		int backup = energy_ball[i];
		energy_ball.erase(energy_ball.begin() + i);

		// dfs 호출
		dfs(level + 1, sum + cur_energy);

		// i번째 에너지 구슬을 다시 원상복구
		energy_ball.insert(energy_ball.begin() + i, backup);
	}

	return;
}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N;
	energy_ball.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> energy_ball[i];
	}

	dfs(0, 0);

	cout << result << endl;

	return 0;
}
