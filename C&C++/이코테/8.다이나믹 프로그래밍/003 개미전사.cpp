// 점화식 : a_i = max(a_(i-1), a_(i-2) + k_i)
#include <iostream>

using namespace std;

int arr[101] = { 0 };
int d[101] = { 0 };

int main() {
	// input
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	// DP
	d[1] = arr[1]; // 창고가 한개
	d[2] = max(arr[1], arr[2]); // 창고가 두개
	for (int i = 3; i < N+1; i++) {
		d[i] = max(d[i - 1], d[i - 2] + arr[i]);
	}

	cout << d[N];

	return 0;
}