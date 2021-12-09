#include <iostream>

using namespace std;

int directY[8] = { -1,-1,0,1,1,1,0,-1 };
int directX[8] = { 0,1,1,1,0,-1,-1,-1,};

int map[5][4];


//(y,x)좌표 8방향에 1이 있으면 불안정
bool isStable(int y, int x) {

	for (int i = 0; i < 8; i++) {
		int dy = y + directY[i];
		int dx = x + directX[i];
				
		if (dy < 0 || dx < 0 || dy > 4 || dx > 3)continue;
				
		if (map[dy][dx] == 1) {
			return false;
		}
	}

	return true;
}

void init() {
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 4; x++) {
			cin >> map[y][x];
		}
	}
}

int main() {

	init();
	
	bool flag = 0;

	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 4; x++) {
			if (map[y][x] == 1) {
				if (isStable(y, x) == false) {
					flag = 1;
					break;
				}
			}
		}
	}

	if (flag == 1) {
		cout << "불안정한 상태";
	}
	else {
		cout << "안정된 상태";
	}

	return 0;
}