#include <iostream>

using namespace std;

int main() {
	int* simData[5];
	int a, b, c, d, e;

	simData[0] = &a;
	simData[1] = &b;
	simData[2] = &c;
	simData[3] = &d;
	simData[4] = &e;

	cin >> a >> b >> c >> d >> e;

	int max_age = -21e8;
	int min_age = 21e8;

	for (int i = 0; i < 5; i++) {
		if (*simData[i] > max_age) max_age = *simData[i];
		else if (*simData[i] < min_age) min_age = *simData[i];
	}

	cout << "MAX:" << max_age << endl << "MIN:" << min_age;

}