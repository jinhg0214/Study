#include <iostream>

using namespace std;

struct node {
	int n;
	char ch;
};

int main() {
	int n;
	cin >> n;

	node arr[100];

	for (int i = 0; i < n; i++) {
		cin >> arr[i].n >> arr[i].ch;
	}

	// 삽입정렬
	for (int i = 0; i < n; i++) {
		for (int j = i; j > 0; j--) {
			if (arr[j - 1].n > arr[j].n) {
				swap(arr[j - 1], arr[j]);
			}
			else if (arr[j - 1].n == arr[j].n) {
				if (arr[j - 1].ch > arr[j].ch) {
					swap(arr[j - 1], arr[j]);
				}
			}
			else
				break;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i].n << " " << arr[i].ch << endl;
	}

	return 0;
}