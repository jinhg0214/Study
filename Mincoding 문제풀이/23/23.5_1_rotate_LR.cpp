#include <iostream>

using namespace std;

int main() {
	int arr[5] = { 3,5,1,9,7 };
	int tmp;
	char ch;

	for (int i = 0; i < 4; i++) {
		cin >> ch;

		//rotate >>
		if(ch=='R'){
			tmp = arr[4];

			for (int i = 3; i >= 0; i--) {
				arr[i + 1] = arr[i];
			}
			arr[0] = tmp;
		}
		else if (ch == 'L') {
			tmp = arr[0];

			for (int i = 0; i <= 3; i++) {
				arr[i] = arr[i+1];
			}
			arr[4] = tmp;
		}
	}
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << " ";
	}
	

	return 0;
}