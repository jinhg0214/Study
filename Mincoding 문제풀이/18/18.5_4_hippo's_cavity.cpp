#include <iostream>

using namespace std;

int main() {
	int up[5];
	int down[5];

	for (int i = 0; i < 5; i++) {
		cin >> up[i];
	}
	for (int i = 0; i < 5; i++) {
		cin >> down[i];
	}

	int cnt = 0;
	for (int i = 0; i < 5; i++) {
		if (up[i] == 1 && down[i] == 1) {
			cnt++;
		}
	}

	cout << cnt << "개";

	return 0;
}