#include <iostream>

using namespace std;

int main() {
	int a[4];
	int a_ptr = 0;

	int b[4];
	int b_ptr = 0;

	int res[8];
	int res_ptr = 0;

	for (int i = 0; i < 4; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> b[i];
	}

	while (a_ptr != 4 && b_ptr != 4) {
		if (a[a_ptr] <= b[b_ptr]) {
			res[res_ptr] = a[a_ptr];
			res_ptr++;
			a_ptr++;
		}
		else {
			res[res_ptr] = b[b_ptr];
			res_ptr++;
			b_ptr++;
		}
	}

	while (a_ptr != 4) {
		res[res_ptr] = a[a_ptr];
		res_ptr++;
		a_ptr++;
	}

	while (b_ptr != 4) {
		res[res_ptr] = b[b_ptr];
		res_ptr++;
		b_ptr++;
	}

	for (int i = 0; i < 8; i++) {
		cout << res[i] << " ";
	}

}