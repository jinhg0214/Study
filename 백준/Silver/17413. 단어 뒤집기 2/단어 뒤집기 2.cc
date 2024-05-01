#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);

	string input;
	bool flag = false;
	stack<char> st;

	getline(cin, input);
	for (char ch : input) {
		if (ch == '<') {
			// 스택 출력
			while (!st.empty()) {
				cout << st.top();
				st.pop();
			}

			flag = true;
			cout << ch;
		}
		else if (ch == '>') {
			flag = false;
			cout << ch;
		}
		
		else if (flag) {
			cout << ch;
		}
		else {
			if (ch == ' ') {
				while (!st.empty()) {
					cout << st.top();
					st.pop();
				}
				cout << ch;
			}
			else {
				st.push(ch);
			}
		}
	}
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
	cout << '\n';

	return 0;
}