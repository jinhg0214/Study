#include <iostream>

using namespace std;

int main() {
	int win[2][3] = {
		3,5,1,
		4,2,6,
	};

	int people[4];

	for (int i = 0; i < 4; i++) {
		cin >> people[i];
	}

	//dat?
	int dat[10] = { 0 };
	for (int y = 0; y < 2; y++) {
		for (int x = 0; x < 3; x++) {
			int idx = win[y][x];
			dat[idx]++;
		} 
	}

	// dat[i]==1 합격
	for (int i = 0; i < 4; i++) {
		int idx = people[i];
		cout << idx << "번 ";
		if (dat[idx] == 1) {
			cout << "합격" << endl;
		}
		else {
			cout << "불합격" << endl;
		}
	}
	

	return 0;
}