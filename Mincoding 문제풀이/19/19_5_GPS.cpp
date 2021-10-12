#include <iostream>

using namespace std;

int main() {
	int input[4][2];
	int vect[4][3] = { 0 };

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 2; x++) {
			cin >> input[y][x];
		}
	}

	for (int i = 0; i < 4; i++) {
		int yy = input[i][0];
		int xx = input[i][1];

		vect[yy][xx] = 5;
	}

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 3; x++) {
			cout << vect[y][x] << " ";
		}
		cout << endl;
	}

	return 0;
}