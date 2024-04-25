#include <iostream>

using namespace std;

int arr[100001];
int front = 0, back = 0;

// 정수 X를 큐에 넣는 연산
void my_queue_push(int x) {
	arr[back++] = x;
}

// 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력
int my_queue_pop() {
	if (front != back) 
		return arr[front++];
	else
		return -1;
}

int my_queue_size() {
	return back - front;
}

bool my_queue_empty() {
	return front == back;
}

int my_queue_front() {
	if (front != back)
		return arr[front];
	else
		return -1;
}

int my_queue_back() {
	if (front != back)
		return arr[back-1];
	else
		return -1;
}


int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);

	int N; cin >> N;
	while (N--) {
		string cmd; cin >> cmd;

		if (cmd == "push") {
			int num; cin >> num;
			my_queue_push(num);
		}
		else if (cmd == "pop") {
			cout << my_queue_pop() << '\n';
		}
		else if (cmd == "size") {
			cout << my_queue_size() << endl;
		}
		else if (cmd == "empty") {
			cout << my_queue_empty() << endl;
		}
		else if (cmd == "front") {
			cout << my_queue_front() << endl;
		}
		else if (cmd == "back") {
			cout << my_queue_back() << endl;
		}
	}

	return 0;
}