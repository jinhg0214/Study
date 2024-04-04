#include <iostream>

using namespace std;

int st[10001];
int st_top = 0;

void push(int X) {
	st[st_top] = X;
	st_top++;
}

int pop() {
	if (st_top == 0) return -1;
	return st[--st_top];
}

void size() {
	cout << st_top << endl;
}

bool empty() {
	if (st_top == 0) 
		return true;
	else
		return false;
}

int top() {
	if (st_top == 0) return -1;
	return st[st_top - 1];
}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	int N;

	cin >> N;

	while (N--) {
		string cmd;
		cin >> cmd;
		
		if (cmd == "push") {
			int num;
			cin >> num;
			push(num);
		}
		else if (cmd == "pop") {
			cout << pop() << endl;
		}
		else if (cmd == "size") {
			size();
		}
		else if (cmd == "empty") {
			cout << empty() << endl;
		}
		else if (cmd == "top") {
			cout << top() << endl;
		}

	}

	return 0;
}



/*
문제 분석
stack을 구현하는 문제

첫번째 줄에 명령의 수 N이 주어짐
N은 1<= N <= 10000이므로 int형 
주어지는 정수는 1보다 크거나 같고, 100,000보다 작다
int형으로 처리 가능

배열로 스택을 구현하므로, int st[10001]; 
(최대 10000개의 push가 발생할 수 있기 때문)
*/