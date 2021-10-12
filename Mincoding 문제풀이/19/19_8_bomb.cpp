#include <iostream>

using namespace std;

char map[4][5] = {
	'_','_','_','_','_',
	'_','_','_','_','_',
	'_','_','_','_','_',
	'_','_','_','_','_'
};

int directY[8] = {-1,-1,0,1,1,1,0,-1};
int directX[8] = {0,1,1,1,0,-1,-1,-1};

void bomb(int y, int x) {
	//y,x 주위로 비산
	for (int i = 0; i < 8; i++) {
		int yy = y + directY[i];
		int xx = x + directX[i];

		// 맵밖으로 나감
		if (yy < 0 || xx < 0 || yy >= 4 || xx >= 5) { continue; }
		map[yy][xx] = '#';
	}
}

int main() {
	int y, x;
	for (int i = 0; i < 2; i++) {
		cin >> y >> x;
		bomb(y, x);
	}

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 5; x++) {
			cout << map[y][x] <<" ";
		}
		cout << endl;
	}

	return 0;
}