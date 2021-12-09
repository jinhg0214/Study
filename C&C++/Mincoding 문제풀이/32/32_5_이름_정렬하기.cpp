#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool compare(string front, string back) {
	if (front.length() < back.length()) return true;
	if (front.length() > back.length()) return false;
	
	return front < back;
}

int main() {
	// freopen_s(new FILE*, "test.txt", "r", stdin);

	int n;
	cin >> n;

	string name[100];
	for (int i = 0; i < n; i++) {
		cin >> name[i];
	}

	sort(name, name + n, compare);

	for (int i = 0; i < n; i++) {
		cout << name[i] << endl;
	}
	
	return 0;
}