#include <iostream>

using namespace std;

int directY[4] = {0, -1, 0, 1};
int directX[4] = {-1, 0, 1, 0};
 
int main() {
	int map[7][7] = {
		0,0,0,0,0,0,0,
		0,0,1,0,1,0,0,
		0,1,2,0,2,1,0,
		0,0,1,2,1,0,0,
		0,0,2,1,0,1,0,
		0,1,1,0,0,0,0,
		0,0,0,0,0,0,0
	};

	// 흰돌 놓을곳 좌표
	int a, b;

	cin >> a >> b;

	map[a][b] = 1;
	
	int cnt = 0;
	bool flag;

	// 맵을 전체를 돌면서, 검은돌의 4면이 둘러쌓였는지 확인
	for (int y = 1; y <= 5; y++) {
		for (int x = 1; x <= 5; x++) {

			// 현재 위치가 검은돌이라면 주위를 살펴봄
			if (map[y][x] == 2) {
				
				flag = 1;
				for (int i = 0; i < 4; i++) {
					int yy = y + directY[i];
					int xx = x + directX[i];

					// 흰돌이 아니라면 바로 종료
					if (map[yy][xx] != 1) {
						flag = 0;
						break;
					}

				}
				if (flag == 1) {
					cnt++;
				}
			}
			

		}
	}
	cout << cnt;



	return 0;
}