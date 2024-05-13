#include <iostream>

using namespace std;

int counting(int n, int k) {
	int cnt = 0;

	for (long long int i = k; i <= n; i = i * k) {
		cnt += n / i;
	}

	return cnt;
}


int main() {
	int N, M; // N, M <= 20억 int +-21억

	cin >> N >> M;

	int five = counting(N, 5) - (counting(N - M, 5) + counting(M, 5));
	int two = counting(N, 2) - (counting(N - M, 2) + counting(M, 2));

	cout << min(five, two);


	return 0;
}