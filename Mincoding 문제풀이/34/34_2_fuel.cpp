#include <iostream>
#include <string>

using namespace std;

string fuel;

int bsearch(int start, int end) {
	int Max = -1;

	while (1) {
		int mid = (start + end) / 2;
		if (start > end) break;
		if (fuel[mid] == '#') {
			if (Max < mid) {
				Max = mid;
				start = mid + 1;
			}
		}
		else {
			end = mid - 1;
		}
	}

	return Max;
}

int main() {
	cin >> fuel;

	cout << to_string(bsearch(0, 9)+1) + "0%";
	
	return 0;
}