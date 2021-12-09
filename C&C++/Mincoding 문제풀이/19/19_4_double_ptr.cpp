#include <iostream>

using namespace std;

int main() {
	int** t;
	int** Q;

	int* p;
	int* K;

	int g;

	cin >> g;

	p = &g;
	K = &g;

	t = &p;
	Q = &K;

	cout << **t << " " << *K;

	return 0;
}