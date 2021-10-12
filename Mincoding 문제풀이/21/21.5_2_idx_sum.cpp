#include <iostream>

using namespace std;

int main() {
	int arr[3][4] = {
		3,4,1,5,
		3,4,1,3,
		5,2,3,6
	};

	int sum[4] = { 0 };

	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 3; y++) {
			sum[x] += arr[y][x];
		}
	}

	int i;

	cin >> i;
	
	cout << sum[i]; 

	return 0;
}