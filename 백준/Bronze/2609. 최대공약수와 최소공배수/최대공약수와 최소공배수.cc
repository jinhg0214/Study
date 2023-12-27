#include <iostream>
#include <numeric>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	cout << gcd(a, b) << endl << lcm(a, b);

	return 0;
}