#include <iostream>

using namespace std;

int main() {

	int arr[7][4];
	int a = 1;
	for (int y = 0; y < 7; y++) {
		for (int x = 0; x< 4; x++) {
			arr[y][x] = a;
			a++;
		}
	}

	int n[3];

	for (int i = 0; i < 3; i++) {
		cin >> n[i];
	}

	for (int i = 0; i < 3; i++) {
		for (int x = 0; x < 4; x++) {
			int yy = n[i];
			arr[yy][x] = 0;
		}
	}

	for (int y = 0; y < 7; y++) {
		for (int x = 0; x < 4; x++) {
			cout << arr[y][x] << " ";
		}
		cout << endl;
	}

}