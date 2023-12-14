#include <iostream>
#include <math.h>

using namespace std;

int main() {
	unsigned long long int n;
	cin >> n;

	unsigned long long int res = sqrt(n);

	while (res * res < n) {
		res++;
	}
	
	cout << res;

	return 0;
}