#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

bool my_binary_search(int target) {
	int start = 0;
	int end = v.size() - 1;
	int mid;
	while (start <= end) {
		mid = (start + end) / 2;
		if (target == v[mid]) return true;
		
		if (target < v[mid]) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}

	}

	return false;
}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);

	int N;
	scanf("%d", &N);
	v.resize(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &v[i]);
	}

	sort(v.begin(), v.end());

	int M;
	scanf("%d", &M);
	while (M--) {
		int num; scanf("%d", &num);
		printf("%d\n", my_binary_search(num));
	}
}
