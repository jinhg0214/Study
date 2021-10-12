#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool compare(string front, string back) {
	// 1. 길이순
	if (front.length() < back.length()) return true;
	else if (front.length() > back.length()) return false;
	
	// 사전순
	else {
		return front < back;
	}
}

int main() {
	int n;
	cin >> n;
	
	string str[21];
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}

	sort(str, str+n, compare);

	for (int i = 0; i < n; i++) {
		cout << str[i] << endl;
	}

	return 0;
}