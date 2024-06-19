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


	// 1. 뒤에서부터 두개씩 확인하면서, y가 x보다 큰 경우 찾기
	// 2. x, y를 저장해두고, 다시 뒤에서부터 x보다 큰 값을 찾아 x와 swap
	// 3. 이후 y부터 sort하기

	int x, y;
	for (int i = N - 1; i > 0; i--) {
		x = v[i - 1];
		y = v[i];
		if (x < y) {
			for (int j = N - 1; j > 0; j--) {
				if (x < v[j]) {
					swap(v[i-1], v[j]);
					sort(v.begin() + i, v.end());
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