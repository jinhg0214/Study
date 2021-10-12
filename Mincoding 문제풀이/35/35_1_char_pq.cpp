#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<char, vector<char>, less<char>> q;

int main() {

	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		q.push(str[i]);
	}

	while (!q.empty()) {
		cout << q.top();
		q.pop();
	}

	return 0;
}