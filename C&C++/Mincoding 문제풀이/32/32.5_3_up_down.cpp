#include <iostream>
#include <string>

using namespace std;

int front = 1, tail = 50;

void UpDown(int n, string str) {

	if (str == "UP") { front = n + 1; }
	else if(str == "DOWN"){ tail = n - 1; }

	return;
}

int main() {
	freopen_s(new FILE*, "test.txt", "r", stdin);

	int T;
	cin >> T;
	while (T--) {
		int input_n;
		string input_str;
		cin >> input_n >> input_str;

		UpDown(input_n, input_str);
	}

	if (front > tail) {
		cout << "ERROR";
	}
	else if (front == tail) { 
		cout << front; 
	}
	else {
		cout << front << " ~ " << tail;
	}


	return 0;
}