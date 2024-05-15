#include <iostream>
#include <numeric>
 
using namespace std;

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	int N, S;
	cin >> N >> S;

	int tmp;
	cin >> tmp;

	int res = tmp - S;

	for (int i = 1; i < N; i++){
		cin >> tmp;
		res = gcd(res, tmp-S);
	}

	cout << res;

	return 0;
}