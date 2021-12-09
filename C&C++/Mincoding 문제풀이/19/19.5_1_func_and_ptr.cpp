#include <iostream>

using namespace std;

void BBQ(int* a, int* b) {
	int arr[5];
	int max = -21e8;
	int min = 21e8;
	
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
		if (arr[i] > max) {
			max = arr[i];
		}
		if (arr[i] < min) {
			min = arr[i];
		}
	}

	*a = max;
	*b = min;

	return;
}

int main() {
	int a, b;

	BBQ(&a, &b);

	cout << "a=" << a << endl
		<< "b=" << b << endl;

	return 0;
}