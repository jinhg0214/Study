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