#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int card;
vector<int> arr;

int main() {
    // freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> card;
		arr[i] = card;
	}

	sort(arr.begin(), arr.end());

	cin >> M;
	while (M--) {
		cin >> card;
		cout << upper_bound(arr.begin(), arr.end(), card) - lower_bound(arr.begin(), arr.end(), card) << " ";
	}

	return 0;
}