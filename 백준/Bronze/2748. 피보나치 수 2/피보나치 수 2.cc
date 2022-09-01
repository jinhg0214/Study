#include<iostream>

using namespace std;
long long int arr[99] = { 0 };

long long int fibo(int n) {
	if (n == 0) {
		return 0;
	}
	if (arr[n] != 0) {
		return arr[n];
	}

	arr[n] = fibo(n - 2) + fibo(n - 1);
	
	return arr[n];
}

int main() {
	int n;
	cin >> n;

	arr[0] = 0;
	arr[1] = 1;

	cout << fibo(n);

	return 0;
}