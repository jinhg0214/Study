// 점화식 : a_i = a_(i-1) + a_(i-2) + a_(i-2)
#include <iostream>

using namespace std;

int d[1001] ={0};

int main() {
	int n;
	cin >> n;

	d[1] = 1;
	d[2] = 3;

	for(int i=3; i<n+1; i++){
		d[i] = d[i - 1] + 2 * d[i - 2] % 796796;
	}

	cout << d[n];

	return 0;
}