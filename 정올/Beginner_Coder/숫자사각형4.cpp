/*
1
1 1 1 1 1
2 2 2 2 2
3 3 3 3 3
4 4 4 4 4
5 5 5 5 5

2 
1 2 3 4 5
5 4 3 2 1
1 2 3 4 5
5 4 3 2 1
1 2 3 4 5

3 
1 2 3 4 5
2 4 6 8 10
3 6 9 12 15
4 8 12 16 20
5 10 15 20 25

*/

#include <iostream>

using namespace std;

int main() {

	int n, type;

	cin >> n >> type;

	switch (type) {
		case 1:
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					cout << i << " ";
				}
				cout << endl;
			}
			break;
		case 2:
			for (int i = 1; i <= n; i++) {
				if (i % 2 == 1) {
					for (int j = 1; j <= n; j++) {
						cout << j << " ";
					}
				}
				else {
					for (int j = n; j >= 1; j--) {
						cout << j << " ";
					}
				}
				cout << endl;
			}
			break;
		case 3:
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					cout << i * j << " ";
				}
				cout << endl;
			}
			break;
		default:
			break;
	}
	return 0;
}