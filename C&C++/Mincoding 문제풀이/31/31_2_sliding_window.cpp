#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int arr[100001];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int sum = 0;
	int w = 4;
	for (int i = 0; i < w; i++) {
		sum += arr[i];
	}

	int min = sum;
	for (int i = 0; i <= n-w; i++) {
		if (sum < min) {
			min = sum;
		}
		sum += arr[i + w];
		sum -= arr[i];
	}

	cout << min;


	return 0;
}