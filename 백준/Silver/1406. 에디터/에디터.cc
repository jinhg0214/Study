#include <iostream>
#include <stack>

using namespace std;

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);

	string str;  cin >> str;

	stack<char> left;
	stack<char> right; // right은 거꾸로 쌓이는것에 주의할 것

	for (char ch : str) {
		left.push(ch);
	}

	int M; cin >> M;
	while (M--) {
		char cmd, c; cin >> cmd;
		switch (cmd)
		{
		case 'L':
			if (!left.empty()) {
				right.push(left.top());
				left.pop();
			}
			break;
		case 'D':
			if (!right.empty()) {
				left.push(right.top());
				right.pop();
			}
			break;
		case 'B':
			if (!left.empty()) {
				left.pop();
			}
			break;
		case 'P':
			cin >> c;
			left.push(c);
			break;
		default:
			break;
		}
	}

	while (!left.empty()) {
		right.push(left.top());
		left.pop();
	}

	while (!right.empty()) {
		cout << right.top();
		right.pop();
	}

	return 0;
}