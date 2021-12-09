#include <iostream>

using namespace std;

int main() {
	int arr[7] = { 3,5,5,6,9,1,2 };

	int start, end;

	cin >> start >> end;
	
	for (int i = 0; i < start; i++) {
		cout << arr[i] << " ";
	}

	for (int i = end; i >= start; i--) {
		cout << arr[i] << " ";
	}

	if (end < 7) {
		for (int i = end + 1; i < 7; i++) {
			cout << arr[i] << " ";
		}
	}
	


	return 0;
}