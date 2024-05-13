#include <iostream>

using namespace std;

long long d2(int n) {
	long long int cnt = 0;

	for (long long int i = 2; i <= n; i *= 2) {
		cnt += n / i;
	}
	return cnt;
}

long long d5(int n) {
	long long int cnt = 0;

	for (long long int i = 5; i <= n; i *= 5) {
		cnt += n / i;
	}
	return cnt;
}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	int N, M;
	cin >> N >> M;

	int de = -1;

	long long int five = d5(N) - d5(N - M) - d5(M);
	long long int two = d2(N) - d2(N - M) - d2(M);

	cout << min(five, two);

	return 0;
}