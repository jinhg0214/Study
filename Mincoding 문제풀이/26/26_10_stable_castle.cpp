#include <iostream>

using namespace std;


bool IsStableCastle(int castle[][4]) {

	bool isStable = true;

	// 각 열마다 위에서 아래로 확인
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 3; y++) {
			if (castle[y][x] > castle[y + 1][x]) {
				isStable = false;
				break;
			}
		}
	}

	return isStable;

}

int main() {
	int castle[4][4] = {
		0,0,0,0,
		0,1,1,0,
		2,2,3,0,
		1,3,3,1,
	};

	if (IsStableCastle(castle) == true) {
		cout << "안전한성";
	}
	else {
		cout << "안전하지않은성";
	}

	return 0;
}