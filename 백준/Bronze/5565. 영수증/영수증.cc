#include <iostream>

using namespace std;

int main() {
	// freopen_s(new FILE*, "sample_input.txt", "r", stdin);

	int total;

	cin >> total;
	for (int i = 0; i < 9; i++) {
		int tmp;
		cin >> tmp;
		total = total - tmp;
	}
	cout << total;

	return 0;
}