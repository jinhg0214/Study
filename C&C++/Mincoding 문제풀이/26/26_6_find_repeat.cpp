#include <iostream>

using namespace std;

int main(){
	int y, x;
	int map[7][7] = { 0 };

	bool flag = false;

	for (int i = 0; i < 6; i++) {
		cin >> y >> x;
		if (map[y][x] == 0) {
			map[y][x] = 1;
		}
		else if (map[y][x] == 1) {
			flag = true;
			break;
		} 
	}

	if (flag == true) {
		cout << "중복된좌표발견";
	}
	else {
		cout << "중복없음";
	}
	return 0;
}