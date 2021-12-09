#include <iostream>

using namespace std;


int main() {
	int arr[6];
	int sum_arr[6];
	int sum = 0;
	for (int i = 0; i < 6; i++) {
		cin >> arr[i];
		sum += arr[i];

		sum_arr[i] = sum;
	}


	for (int i = 0; i < 6; i++) {
		cout << sum_arr[i] << " ";
	}


	return 0;
}