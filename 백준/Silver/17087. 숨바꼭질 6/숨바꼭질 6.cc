#include <iostream>
#include <numeric>
#include <cmath>
#include <vector>

#define MAX 100001

using namespace std;

int N, S;
vector<int> v;

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> S;

	// S를 원점으로 두고 각 거리들의 절대값을 저장
	for (int i = 0; i < N; i++) {
		int tmp; cin >> tmp;
		v.push_back(abs(tmp - S));
	}

	if (v.size() == 1) {
		cout << v[0];
		return 0;
	}

	int res = gcd(v[0], v[1]);

	for (int i = 1; i < N; i++) {
		res = gcd(res, v[i]);
	}

	cout << res;

	return 0;
}
