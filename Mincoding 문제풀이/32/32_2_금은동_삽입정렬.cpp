#include <iostream>

using namespace std;


int main() {
	int n;

	cin >> n;

	int arr[1001] = { 0 };
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	//insert sort 
	for (int i = 0; i < n; i++) {
		for (int j = i; j > 0; j--) {
			if (arr[j - 1] < arr[j]) {
				swap(arr[j - 1], arr[j]);
			}
		}
	}

	cout << "금" << arr[0] << endl
		<< "은" << arr[1] << endl
		<< "동" << arr[2] << endl;


	return 0;
}