#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 문자열 a, b를 더해 결과를 문자열로 리턴하는 함수
string BinSum(string a, string b) {
	string result;

	if (a.size() < b.size()) {
		swap(a, b);
	}
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	int carry = 0;

	// b가 더 작으므로
	for (int i = 0; i < b.size(); i++) {
		int sum = (a[i] - '0') + (b[i] - '0') + carry;
		if (sum > 1) carry = 1;
		else carry = 0;
		result.push_back((sum % 2) + '0');
	}

	// a의 나머지 더해주기
	for (int i = b.size(); i < a.size(); i++) {
		int sum = (a[i] - '0') + carry;
		if (sum > 1) carry = 1;
		else carry = 0;
		result.push_back((sum % 2) + '0');
	}
	
	if (carry) result.push_back('1');

	reverse(result.begin(), result.end());

	if (result.find_first_of('1') != string::npos) {
		result = result.substr(result.find_first_of('1'));
	}
	else {
		result = "0";
	}

	return result;
}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	int T; cin >> T;
	while (T--) {
		string a, b;
		cin >> a >> b;

		cout << BinSum(a, b) << endl;
	}

	return 0;
}