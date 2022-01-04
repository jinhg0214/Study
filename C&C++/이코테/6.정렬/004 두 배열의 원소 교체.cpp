#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, K, temp;
	cin >> N >> K;

	vector<int> a, b;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		a.push_back(temp);
	}

	for (int i = 0; i < N; i++) {
		cin >> temp;
		b.push_back(temp);
	}

	// a는 오름차순, b는 내림차순 정렬한다
	sort(a.begin(), a.end(), less<int>());
	sort(b.begin(), b.end(), greater<int>());

	// K번 교환 수행
	for (int i = 0; i < K; i++) {
		if (a[i] < b[i]) {
			swap(a[i], b[i]);
		}
		else {
			break;
		}
	}
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += a[i];
	}

	cout << sum;

	return 0;
}