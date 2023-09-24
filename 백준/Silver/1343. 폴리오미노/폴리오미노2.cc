#include <iostream>
#include <string>

using namespace std;

int main() {
	string board, result;
	int cnt = 0;

	cin >> board;

	// 문자열을 하나씩 확인하면서 'X'를 확인함
	for (int i = 0; i < board.length(); i++) {
		if (board[i] == 'X') { cnt++; }

		if (board[i] == '.') {
			result += '.';
			if (cnt % 2 != 0) {
				break;
			}
			else cnt = 0;
		}

		if (cnt == 2 && board[i + 1] != 'X') {
			result += "BB";
			cnt = 0;
		}
		else if (cnt == 4) {
			result += "AAAA";
			cnt = 0;
		}
	}

	if (cnt % 2 == 1) cout << -1;
	else cout << result;
	

	return 0;
}
