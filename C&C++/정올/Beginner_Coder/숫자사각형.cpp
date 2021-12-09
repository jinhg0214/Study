/*
1 2 3 4 5
6 7 8 9 10
11 12 .... 이런식으로 출력하기

*/


#include <iostream>

using namespace std;

int main() {
	int s, e;
	cin >> s >> e;

	if (s < e) {
		for (int j = s; j <= e; j++) {
			for (int i = 1; i <= 9; i++) {
				cout << j << " * " << i << " = " << j * i << "\t";
				if (i % 3 == 0) cout << endl;
			}
			cout << endl;
		}
	}
	else {
		for (int j = s; j >= e; j--) {
			for (int i = 1; i <= 9; i++) {
				cout << j << " * " << i << " = " << j * i << "\t";
				if (i % 3 == 0) cout << endl;
			}
			cout << endl;
		}
	}



	return 0;
}