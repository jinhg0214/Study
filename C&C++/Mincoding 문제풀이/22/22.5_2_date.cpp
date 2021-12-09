// Lv : n, br : 2(OX)

#include <iostream>

using namespace std;

char ox[3] = "xo";
char path[50];

void date(int Lv, int n) {

	if (Lv == n)
	{
		cout << path << endl;
		return;
	}
	// O 또는 X이므로 두가지 가지
	for (int x = 0; x < 2; x++) {
		path[Lv] = ox[x];
		date(Lv + 1, n);
		path[Lv] = 0;
	}

}

int main() {
	int n;
	cin >> n;

	date(0, n);

	return 0;
}