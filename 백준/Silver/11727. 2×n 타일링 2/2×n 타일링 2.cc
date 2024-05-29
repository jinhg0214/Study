#include <iostream>

using namespace std;

int arr[1001];

int main() {
	int n;
	cin >> n;

	arr[1] = 1;
	arr[2] = 3;

	for (int i = 3; i <= 1000; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2] + arr[i - 2]) % 10007;
	}
    // [n-1]에 1x2을 붙인것, [n-2]에 2x1 2개 붙인것, [n-2]에 2x2 1개 붙인것

	cout << arr[n];

	return 0;
}