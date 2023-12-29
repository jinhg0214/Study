#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 소문자로 변환하는 함수
string lower(string str) {
	string result;
	for (char ch : str) {
		if ('A' <= ch && ch <= 'Z') {
			result.push_back(ch + 32);
		}
		else {
			result.push_back(ch);
		}
	}
	return result;
}

// 소문자 대문자 구분하지 않고 비교하는 함수 
bool compare(string first, string second) {
	string lower_first = lower(first);
	string lower_second = lower(second);

	if (lower_first < lower_second) return true;
	else return false;
}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);

	while (1) {
		int n;
		cin >> n;
		if (n == 0) break;

		vector<string> list(n);
		for (int i = 0; i < n; i++) {
			cin >> list[i];
		}

		sort(list.begin(), list.end(), compare);

		cout << list[0] << endl;
	}
	return 0;
}