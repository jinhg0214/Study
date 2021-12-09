#include <iostream>

using namespace std;


void go(int Lv, int n) {

	cout << Lv;

	if (Lv == n) {
		return;
	}
	go(Lv + 1, n);
	go(Lv + 1, n);

}

int main() {

	int n;

	cin >> n;

	go(0, n);

	return 0;
}