#include <iostream>
using namespace std;

int BinSearch(int start, int end, int target){
	int mid=0;
	while (start <= end) {

		mid = (start + end) / 2;

		if (mid * mid == target) {
			return mid;
		}
		else if (mid * mid < target) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}

	return mid;
}

int main() {
	int n;
	cin >> n;

	cout << BinSearch(0, 11, n);

	return 0;
}