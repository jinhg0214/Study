#include <iostream>
#include <stack>

using namespace std;

int N;
int ans[1000001], seq[1000001];
stack<int> st;


int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> seq[i];
	}

	for (int i = N - 1; i >= 0; i--) {
		// seq[i] 에 대해서 오큰수 찾기
		while (!st.empty() && st.top() <= seq[i]) {
			st.pop();
		}

		if (st.empty()) ans[i] = -1;
		else ans[i] = st.top();

		st.push(seq[i]);
	}

	for (int i = 0; i < N; i++) {
		cout << ans[i] << " ";
	}

	return 0;
}