#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> stack;

void push(int n) {
	stack.push_back(n);
}

void printLast() {
	cout << stack[stack.size()-1] << endl;
}

void pop() {
	stack.pop_back();
}

int main() {
	//freopen_s(new FILE*, "test.txt", "r", stdin);

	int t;
	cin >> t;

	while (t--) {
		string cmd;
		cin >> cmd;

		if (cmd == "push") {
			int n;
			cin >> n;
			push(n);
		}
		else if (cmd == "printLast") {
			printLast();
		}
		else if (cmd == "pop") {
			pop();
		}
	}

	return 0;
}