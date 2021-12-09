#include <iostream>

using namespace std;

int arr[10] = {
		4,4,5,7,8,10,20,22,23,24
};
int n;

int bsearch(int start, int end) {
	if (start > end) return -1;

	int mid = (start + end) / 2;
	if (arr[mid] == n) {
		return mid;
	}
	else if (arr[mid] > n) {
		return bsearch(start, mid - 1);
	}
	else {
		return bsearch(mid + 1, end);
	}
}

int main() {
	
	cin >> n;

	if (bsearch(0, 9) != -1) {
		cout << "O";
	}
	else {
		cout << "X";
	}

	return 0;
}