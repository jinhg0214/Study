#include <iostream>
#include <algorithm>

using namespace std;

struct country {
	int num;
	int gold;
	int silver;
	int bronze;

	bool operator<(const country &b) {
		// 1. 금메달 수가 더 많은 나라(내림차순 정렬)
		if (this->gold > b.gold) return true;
		if (this->gold < b.gold) return false;

		// 2. 금메달 수가 같으면, 은메달 수가 더 많은 나라
		if (this->silver > b.silver) return true;
		if (this->silver < b.silver) return false;

		// 3. 금, 은메달 수가 모두 같으면, 동메달 수가 더 많은 나라 
		if (this->bronze > b.bronze) return true;
		else return false;
	}
} country[1005];

int N, K, result = 0, val = 0;

int main() {
	// freopen_s(new FILE*, "sample_input.txt", "r", stdin);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> country[i].num >> country[i].gold >> country[i].silver >> country[i].bronze;
	}

	sort(country, country + N);

	for (int i = 0; i < N; i++) {
		if (country[i].num == K) {
			result = i;
			break;
		}
	}

	for (int i = result - 1;; i--) {
		if (country[i].gold != country[result].gold || country[i].silver != country[result].silver || country[i].bronze != country[result].bronze) {
			break;
		}
		val++; // 동점 국가 파악ss
	}

	cout << result - val + 1 << endl;

	return 0;
}