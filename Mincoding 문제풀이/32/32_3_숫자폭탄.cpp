#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	 freopen_s(new FILE*, "test.txt", "r", stdin);
	// Init
	int n;
	cin >> n;

	int arr[30];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// 스택에 넣어봄
	stack<int> st;
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		int num = arr[i];
		if (st.empty()) {
			st.push(num);
			cnt = 1;
			continue;
		}
		if (num == st.top()) { // 스택의 top과 현재 넣는 수가 같다면 카운트증가
			cnt++;
			st.push(num);
			if (cnt == 3) { // 카운트가 3개가 되면 터짐
				st.pop();
				st.pop();
				st.pop();
				
			}
		}
		else { // 아니라면 계속 넣고 개수를 1로 초기화
			st.push(num);
			cnt = 1;
		}
	}

	// 스택에서 꺼내서 정렬 후 출력
	vector<int> res;
	while (!st.empty()) {
		res.push_back(st.top());
		st.pop();
	}

	sort(res.begin(), res.end(), less<int>());

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}

	return 0;
}