#include <iostream>

using namespace std;

int main() {

	int field[5] = { 0 };

	int pos;
	int life;

	cin >> pos >> life;

	while (life>=0) {
		field[pos] = life;

		// 출력
		for (int i = 0; i < 5; i++) {
			if (field[i] == 0) {
				cout << '_';
			}
			else {
				cout << field[i];
			}
		}
		cout << endl;

		// 움직임
		field[pos] = 0;
		pos++;
		life--;
	}

	return 0;
}