#include <iostream>
#include <algorithm>

using namespace std;

// 유클리드 호제법을 이용한 최대공약수 구하기
int gcd(int a, int b) {
	if (a % b == 0) return b;
	return gcd(b, a % b);
}

// 최대공약수를 통한 최소 공배수 구하기
int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

int main() {
	int T; cin >> T;
	while (T--) {
		int a, b;
		cin >> a >> b;
		if (a < b) swap(a, b);

		cout << lcm(a, b) << endl;
	}
	

	return 0;
}