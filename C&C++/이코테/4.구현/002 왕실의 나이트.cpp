#include <iostream>


using namespace std;

int direct[8][2] = { -2,-1, -2,1, 2,-1, 2,1, -1,-2, 1,-2, -1,2, 1,2 };

int main() {
	char input[3] = "";
	int row, col;

	cin >> input; // a2 <- 알파벳 숫자가 같이들어옴
	
	row = input[1] - '0' - 1;
	col = input[0] - 'a';

	int cnt = 0;
	for (int t = 0; t < 8; t++) {
		int dy = row + direct[t][0];
		int dx = col + direct[t][1];

		if (dy < 0 || dx < 0 || dy > 8 || dx > 8) continue; // 경계 처리
		cnt++;
	}

	cout << cnt;

	return 0;
}