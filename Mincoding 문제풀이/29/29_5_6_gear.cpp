#include <iostream>

using namespace std;

int gear[4][3] = {
		3,7,4,
		2,6,9,
		5,1,2,
		3,6,7,
};

int input[4];

void rotateGear(int gearNum, int cnt) {

	for (int i = 0; i < cnt; i++) {
		int tmp = gear[gearNum][2];
		gear[gearNum][2] = gear[gearNum][1];
		gear[gearNum][1] = gear[gearNum][0];
		gear[gearNum][0] = tmp;
	}
	
}

int main() {
	


	for (int i = 0; i < 4; i++) {
		cin >> input[i];
		rotateGear(i, input[i]);
	}
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cout << gear[j][i];
		}
		cout << endl;
	}
	


	return 0;
}