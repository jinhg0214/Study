#include <iostream>

using namespace std;

int main() {
	int map[3][6] = {
		3,5,4,2,2,3,
		1,3,3,3,4,2,
		5,4,4,2,3,5
	};
	char price[6] = "TPGKC";

	char yy, y;
	int xx, x;

	cin >> yy >> xx;
	y = yy - 'A';
	x = xx - 1;
	
	int val = map[y][x];
	char res = price[val-1];

	cout << res;
	return 0;
}