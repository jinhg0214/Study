// 점화식 a_i = min(a_(i-1), a_(i/2), a_(i/3), a_(i/5)) + 1

#include <iostream>

using namespace std;

int d[30001] = { 0 };

int main() {
	int N;
	
	cin >> N;
	for (int i = 2; i < N+1; i++) {
		// a_(i-1)
		d[i] = d[i - 1] + 1;

		if (i % 2 == 0) {
			d[i] = min(d[i], d[i / 2] + 1);
		}
		if (i % 3 == 0) {
			d[i] = min(d[i], d[i / 3] + 1);
		}
		if (i % 5 == 0) {
			d[i] = min(d[i], d[i / 5] + 1);
		}
	}

	cout << d[N];

	return 0;
}