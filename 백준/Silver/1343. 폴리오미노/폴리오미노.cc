/*
C++은 파이썬처럼 간편한 replace가 없어 regex 라이브러리를 사용하였음.

직접 replace를 구현하여 문제를 풀 경우
1. board의 각 자리에 'X' 가 있는지 체크한다
	- 있으면 cnt를 1 증가시킨다
2. '.'를 만나면
	- cnt를 확인하여 "AAAA" 또는 "BB"를 출력
	- cnt가 2 또는 4의 배수가 아니면 -1을 출력

이 과정이 귀찮아서 C++에서 replace를 사용할 수 없나 검색해보다 regex 라이브러리를 공부하게됨.

*/

#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
	
	string board;

	cin >> board;

	board = regex_replace(board, regex("XXXX"), "AAAA");
	board = regex_replace(board, regex("XX"), "BB");

	if (board.find("X") == -1) {
		cout << board;
	}
	else {
		cout << -1;
	}

	return 0;
}