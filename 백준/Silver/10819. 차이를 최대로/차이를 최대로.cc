#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
    // next_permutation 함수를 쓰기 전에는 꼭 정렬해야함
	sort(v.begin(), v.end());

	int max_val = -21e8;
	do {
		int sum = 0;
		for (int i = 0; i < N-1; i++) {
			sum += abs(v[i] - v[i + 1]);
		}
		max_val = max(max_val, sum);

	} while (next_permutation(v.begin(), v.end()));

	cout << max_val;

	return 0;
}