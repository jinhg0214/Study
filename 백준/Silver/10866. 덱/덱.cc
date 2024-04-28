#include <iostream>

using namespace std;

int my_deque[30000];
int front = 15000, back = 15000;

bool empty() {
	return back - front;
}

void push_front(int n) {
	my_deque[--front] = n;;
}

void push_back(int n) {
	my_deque[back++] = n;
}

void pop_front() {
	cout << (empty() ? my_deque[front++] : -1) << '\n';
}

void pop_back() {
	cout << (empty() ? my_deque[--back] : -1) << '\n';
}

void size() {
	cout << back - front << '\n';
}

void dq_front() {
	cout << (back - front ? my_deque[front] : -1) << '\n';
}

void dq_back() {
	cout << (back - front ? my_deque[back-1] : -1) << '\n';
}


int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	int N; cin >> N;
	while (N--) {
		string cmd; 
		int param;
		cin >> cmd;
		if (cmd == "push_front") {
			cin >> param;
			push_front(param);
		}
		else if(cmd == "push_back") {
			cin >> param;
			push_back(param);
		}
		else if (cmd == "pop_front") {
			pop_front();
		}
		else if (cmd == "pop_back") {
			pop_back();
		}
		else if (cmd == "size") {
			size();
		}
		else if (cmd == "empty") {
			cout << (empty() ? "0" : "1") << '\n';
		}
		else if (cmd == "front") {
			dq_front();
		}
		else if (cmd == "back") {
			dq_back();
		}
	}
	
	return 0;
}