#include <iostream>

using namespace std;

int cnt = 0;

void BF(int Lv, int sum, int n) {

	if (Lv == n) {
		if(sum == 7) cnt++;
		return;
	}

	for (int x = 0; x <= 9; x++) {
		BF(Lv + 1, sum + x, n);
	}

}

int main() {
	int n;
	cin >> n;

	BF(0, 0, n);

	cout << cnt;

	return 0;
}