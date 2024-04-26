#include <iostream>
#include <deque>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	deque<int> dq;
	for (int i = 1; i <= N; i++) {
		dq.push_back(i);
	}

	cout << "<";
	while (dq.size() > 1) {
		for (int i = 1; i < K; i++) {
			int now = dq.front();
			dq.pop_front();
			dq.push_back(now);
		}
		cout << dq.front() << ", ";
		dq.pop_front();
	}
	cout << dq.front() << ">";

	return 0;
}