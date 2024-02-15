#include <iostream>
#include <string>

using namespace std;

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);

	int T;	cin >> T;
	cin.ignore(); 
	// 버퍼 비우기
	// 버퍼를 비우지 않으면 '\n' 개행 문자가 남아있게 되는데
	// getline은 '\n' 까지 입력을 받으므로, 첫 입력을 ""로 받는 문제가 발생하기 때문에 비워줘야함

	for (int i = 0; i < T; i++) {
		string input;
		getline(cin, input);
		input += " "; // 띄어쓰기를 기준으로 자를 예정이므로 마지막에 붙여줌

		int a = 0;
		while (1) {
			int b = input.find(" ", a, 1);
			if (b == -1) {
				break;
			}

			string tmp = input.substr(a, b - a);

			for (int i = tmp.size() - 1; i >= 0; i--) {
				cout << tmp[i];
			}
			cout << " ";

			a = b+1;
		}
		cout << endl;
	}

	return 0;
}