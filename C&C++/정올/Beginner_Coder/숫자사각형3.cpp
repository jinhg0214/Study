
/*
1 5 9  13
2 6 10 14 
3 7 11 15
4 8 12 16
*/

#include <iostream>

using namespace std;

int main() {
	int n, idx = 1;
	cin >> n;

	int arr[101][101] = { 0 };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[j][i] = idx++;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}