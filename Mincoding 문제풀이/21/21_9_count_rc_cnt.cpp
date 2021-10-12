#include <iostream>

using namespace std;

int cnt=0;

void count_rc(int Lv, int br, int max) {

	cnt++;

	if (Lv == max) {
		
		return;
	}

	for (int x = 0; x < br; x++) {
		count_rc(Lv + 1, br, max);
	}
	
}

int main() {
	int n, m;

	cin >> n >> m;

	count_rc(0, n, m);

	cout << cnt;

	return 0;
}