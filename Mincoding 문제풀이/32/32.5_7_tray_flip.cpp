#include <iostream>
#include <string>

using namespace std;

char tray[3][6] = {
	'A','B','C','E','F','G',
	'H','I','J','K','L','M',
	'N','O','P','Q','R','S',
};

bool tray_stat[3][6];

int directY[4] = { 0,-1,0,1 };
int directX[4] = { -1,0,1,0 };

// 문자의 위치를 찾아 반환
pair<int, int> FindCh(char ch) {
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 6; x++) {
			if (tray[y][x] == ch) {
				return make_pair(y, x);
			}
		}
	}
}

void Flip(pair<int, int> pos) {
	int y = pos.first;
	int x = pos.second;
	// 자기 자신 뒤집기
	tray_stat[y][x] = !tray_stat[y][x];

	// 자기 상하좌우 뒤집기
	for (int i = 0; i < 4; i++) {
		int dy = y + directY[i];
		int dx = x + directX[i];

		if (dy < 0 || dx < 0 || dy >= 3 || dx >= 6) continue;

		tray_stat[dy][dx] = !tray_stat[dy][dx]; 
	}

}

int main() {
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		pair<int, int> pos = FindCh(str[i]);
		Flip(pos);
	}

	// 출력
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 6; x++) {
			if (tray_stat[y][x] == 0) {
				cout << tray[y][x];
			}
			else {
				cout << "#";
			}
		}
		cout << endl;
	}

	return 0;
}