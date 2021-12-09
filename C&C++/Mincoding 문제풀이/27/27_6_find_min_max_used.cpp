#include <iostream>

using namespace std;

int main() {
	int number[6];
	int used[6] = { 0 };
	char command[7];
	
	for (int i = 0; i < 6; i++) {
		cin >> number[i];
	}

	cin >> command;

	for (int i = 0; i < 6; i++) {
		// find max
		if (command[i] == 'x') {
			int max = -21e8;
			int max_idx;
			for (int j = 0; j < 6; j++) {
				if (max < number[j] && used[j] == 0) {
					max = number[j];
					max_idx = j;
				}
			}

			used[max_idx] = 1;
			cout << number[max_idx];

		}
		// find min
		else {

			int min = 21e8;
			int min_idx;
			for (int j = 0; j < 6; j++) {
				if (min > number[j] && used[j] == 0) {
					min_idx = j;
					min = number[j];
				}
			}
			used[min_idx] = 1;
			cout << number[min_idx];
		}
	}

	return 0;
}