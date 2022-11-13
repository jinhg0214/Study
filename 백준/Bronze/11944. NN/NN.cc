#include <iostream>
#include <string>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	string str = "";
	// n번 붙인다
	for (int i = 0; i < N; i++) {
		str += to_string(N);
	}
	// 답이 길어지는 경우(즉, M자리 보다 길어지는 경우)
	if (str.length() > M) {
		cout << str.substr(0, M);
	}
	else {
		cout << str;
	}
	


	return 0;
}