#include <iostream>

using namespace std;

bool LineCheck(int map[3]) {

	if (map[0] == map[1] && map[0] == map[2])
		return true;
	else
		return false;
}

int main() {
	int map[3][3];

	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			cin >> map[y][x];
		}
	}

	for (int y = 0; y < 3; y++) {
		if (LineCheck(map[y]) == true) {
			cout << map[y][0] << endl;
		}
		else {
			cout << "x" << endl;
		}
	}
}