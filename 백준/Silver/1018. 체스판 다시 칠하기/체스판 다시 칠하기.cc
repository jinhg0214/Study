#include <iostream>
#include <algorithm>

using namespace std;

int cell[51][51];

int M, N;
int cnt = 0, min_cnt=21e8;

// 미리 만들어둔 체스판 2종과 일치하는지 비교시킴
int WB[8][8] = {
	1,0,1,0,1,0,1,0,
	0,1,0,1,0,1,0,1,
	1,0,1,0,1,0,1,0,
	0,1,0,1,0,1,0,1,
	1,0,1,0,1,0,1,0,
	0,1,0,1,0,1,0,1,
	1,0,1,0,1,0,1,0,
	0,1,0,1,0,1,0,1,
};

int BW[8][8] = {
	0,1,0,1,0,1,0,1,
	1,0,1,0,1,0,1,0,
	0,1,0,1,0,1,0,1,
	1,0,1,0,1,0,1,0,
	0,1,0,1,0,1,0,1,
	1,0,1,0,1,0,1,0,
	0,1,0,1,0,1,0,1,
	1,0,1,0,1,0,1,0,
};

int BlackCheck(int y, int x) {
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (cell[y + i][x + j] != BW[i][j]) {
				cnt++;
			}
		}
	}
	return cnt++;
}

int WhiteCheck(int y, int x) {
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (cell[y + i][x + j] != WB[i][j]) {
				cnt++;
			}
		}
	}
	return cnt++;
}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> M >> N;
	for (int y = 0; y < M; y++) {
		for (int x = 0; x < N; x++) {
			char tmp;
			cin >> tmp;
			// 흰색만 1로 표기함
			if (tmp == 'W') {
				cell[y][x] = 1;
			}
		}
	}

	for (int y = 0; y <= M - 8; y++) {
		for (int x = 0; x <= N - 8; x++) {			
			cnt = min(BlackCheck(y, x), WhiteCheck(y, x)); 

			if (cnt < min_cnt) {
				min_cnt = cnt;
			}
		}
	}

	cout << min_cnt;

	return 0;
}

/*
풀이 : 
완전탐색으로 4중 for문을 돌려서 풀이.
각 셀마다 오른쪽 셀과 아래쪽 셀을 비교함. 색이 다르면 덧칠하고 카운트 증가
경계처리에 주의할 것!

그러나 
BBBBBBBBB
BBBBBBBBB
BBBBBBBBB
BBBBBBBBB
BBBBBBBBB
BBBBBBBBB
BBBBBBBBB
BBBBBBBBB
BBBBBBBBW 요 케이스에서 막혔는데

나는 무조건 왼쪽 상단 셀의 색으로만 칠하는걸로 고려했기 때문.
각 셀마다 검은색으로 시도해보고, 흰색으로도 시도해봐야함!!


*/