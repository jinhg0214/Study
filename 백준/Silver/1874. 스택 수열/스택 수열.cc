#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N;
vector<char> ans;
stack<int> st;

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> N;
	int cnt = 1;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;

		while (cnt <= num) {
			ans.push_back('+');
			st.push(cnt++);
		}

		if (st.top() == num) {
			st.pop();
			ans.push_back('-');
		}
		else {
			cout << "NO";
			return 0;
		}
	}

	for (auto e : ans) {
		cout << e << "\n";
	}

	return 0;
}