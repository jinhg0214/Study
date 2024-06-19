#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);

	int N; cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	
	for (int i = N - 1; i > 0; i--) {
		int x = v[i - 1];
		int y = v[i];
		if (x > y) {
			for (int j = N - 1; j > 0; j--) {
				if (x > v[j]) {
					swap(v[i - 1], v[j]);
					sort(v.begin() + i, v.end(), std::greater<int>());
					for (int e : v) {
						cout << e << ' ';
					}
					return 0;
				}
			}
		}
	}
	cout << -1;

	return 0;
}

