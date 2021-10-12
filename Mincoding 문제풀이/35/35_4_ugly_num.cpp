#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
vector<int> res;

int main() {
	int n;
	int input[1501];

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}

	int idx = 0;
	pq.push(1);

	int now; // 중복 제거용
	int before = 0;

	for (int x = 0; x < 10001; x++) {
		while (1) {
			now = pq.top();
			pq.pop();
			if (before != now) break;
		}
		before = now;

		res.push_back(now);

		pq.push(now * 2);
		pq.push(now * 3);
		pq.push(now * 5);
	}

	for (int i = 0; i < n; i++) {
		cout << res[input[i]-1] << " ";
	}

	return 0;
}