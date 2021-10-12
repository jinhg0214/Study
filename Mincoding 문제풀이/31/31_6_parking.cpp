#include <iostream>

using namespace std;

int main() {

	int carSize;

	cin >> carSize;

	int parking[9] = { 1,2,3,3,5,1,0,1,3 };

	int sum = 0;
	for (int i = 0; i < carSize; i++) {
		sum += parking[i];
	}

	int min = 21e8;


	for (int i = 0; i < 9 - carSize; i++) {
		if (min > sum) {
			min = sum;
		}
		sum -= parking[i];
		sum += parking[i + carSize];
	}

	cout << min;

	return 0;
}