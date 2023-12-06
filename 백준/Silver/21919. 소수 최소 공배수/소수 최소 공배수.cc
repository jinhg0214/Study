#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <numeric>

using namespace std;

// n이 소수인지 판별하는 함수
bool IsPrime(int n) {
	// 수학적 증명에 의해 2~sqrt(N)까지만 나눠도 소수인지 판별 가능함
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	int N;
	vector<int> v;
	cin >> N;

	// 1. 소수인 수만 벡터에 삽입
	for (int i = 0; i < N; i++) {
		int tmp; cin >> tmp;
		if (IsPrime(tmp))
			v.push_back(tmp);
	}

	int de = -1;

	// 소수가 없는경우
	if (v.empty()) {
		cout << -1;
		return 0;
	}

	sort(v.begin(), v.end());
	unique(v.begin(), v.end());

	// 2. 최소 공배수 구하기
	unsigned long long res = 1;
	for (int e : v) {
		res = lcm(res, e);
	}

	cout << res;
	

	return 0;
}