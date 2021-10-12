#include <iostream>

using namespace std;

char map[200][200]; 
int expTime[200][200];
int r, c, n;

int directY[4] = { 0,-1,0,1};
int directX[4] = { -1,0,1,0 };

// map에 빈자리를 찾아 폭탄(3초)을 설치하는 함수
void plant(int nowTime) {
	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			if (map[y][x] == '.') {
				map[y][x] = 'O';
				expTime[y][x] = nowTime + 3; // 3초뒤에 터지게 설정
			}
		}
	}
}

// 터질시간이 된 폭탄들을 터트림
void explode(int nowTime) {
	
	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			if (expTime[y][x] == nowTime) {	// 터질시간

				map[y][x] = '.'; // 자기자신의 위치 수정
				// 자기 자신을 포함한 4방향 수정
				for (int i = 0; i < 4; i++) {
					int yy = y + directY[i];
					int xx = x + directX[i];

					if( yy < 0 || xx < 0 || yy > r || xx > c ) continue; // 범위 벗어난경우
					
					map[yy][xx] = '.';
					
					/*
					map과 expTime을 분리시켜 사용해야,
					000 과 같이 연속해서 폭팔하는 경우를 방지할 수 있음!!
					330 
					330
					*/
				}
			}
		}
	}
}

// 초기 폭탄 배치
void init() {
	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			if (map[y][x] == 'O') {
				expTime[y][x] = 3;
			}
		}
	}
}

// 현재 폭탄 상황 보여주기
void showMap() {
	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			cout << map[y][x];
		}
		cout << endl;
	}
}


int main() {
	// freopen_s(new FILE*, "test.txt", "r", stdin);

	cin >> r >> c >> n;

	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			cin >> map[y][x];
		}
	}

	// 0초 : 첫 폭탄 배치
	init();

	
	for (int time = 1; time <= n; time++) {
		explode(time); // 홀수일때 터짐
		if (time % 2 == 0) { // 짝수일때 심음
			plant(time);
		}

	}

	showMap();
}