#include <iostream>

using namespace std;

int main() {
	int s, e;
	cin >> s >> e;

	// 증가하는 경우
	if (s < e) {
		for (int j = 1; j <= 9; j++) {
			for (int i = s; i <= e; i++) {
				cout << i << " * " << j << " = " << i * j << "\t";
			}
			cout << endl;
		}
	}

	// 감소하는 경우
	else {
		for (int j = 1; j <= 9; j++) {
			for (int i = s; i >= e; i--) {
				cout << i << " * " << j << " = " << i * j << "\t";
			}
			cout << endl;
		}
	}


	return 0;
}