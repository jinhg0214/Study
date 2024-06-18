#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	vector<int> sorted = v;

	sort(sorted.begin(), sorted.end());

	next_permutation(v.begin(), v.end());

	if (v == sorted) {
		cout << "-1";
		return 0;
	}

	for (int e : v) {
		cout << e << ' ';
	}	

	return 0;
}