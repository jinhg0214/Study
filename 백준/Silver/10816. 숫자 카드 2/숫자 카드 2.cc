#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int N, M;
int card;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N;
	
	unordered_map<int, int> um;

	for (int i = 0; i < N; i++) {
		cin >> card;
		um[card]++; // 이렇게 간단히 추가할 수 잇음
	}

	cin >> M;
	while (M--) {
		cin >> card;
		cout << um[card] << " ";
	}

	return 0;
}