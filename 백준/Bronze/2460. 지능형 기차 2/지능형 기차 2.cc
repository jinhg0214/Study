#include <iostream>

using namespace std;

int main() {
	// freopen_s(new FILE*, "sample_input.txt", "r", stdin);
	int max = 0, passenger = 0;
	int get_on, get_off;
	for (int i = 1; i <= 10; i++) {
		cin >> get_off >> get_on;
		passenger += get_on;
		passenger -= get_off;
		if (max < passenger) {
			max = passenger;
		}
	}

	cout << max; 
	return 0;
}