#include <iostream>

using namespace std;

struct pos {
	int y;
	int x;
};

int main() {
	pos a[3];

	for (int i = 0; i < 3; i++) {
		cin >> a[i].y >> a[i].x;
	}

	// y검사
	if (a[0].y == a[1].y || a[1].y == a[2].y || a[0].y == a[2].y) {
		cout << "위험";
		return 0;
	}

	if (a[0].x == a[1].x || a[1].x == a[2].x || a[0].x == a[2].x) {
		cout << "위험";
		return 0;
	}

	cout << "안전";


	return 0;
}