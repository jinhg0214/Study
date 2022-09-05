#include <iostream>

using namespace std;

int main() {
	// freopen_s(new FILE*, "sample_input.txt", "r", stdin);

	int student, apple;
	int n, leftover = 0;
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> student >> apple;
		int k = 1;
		while (true) {
			if (apple < k * student) {
				break;
			}
			k++;
		}
		leftover += apple - ((k-1) * student);
	}

	cout << leftover;

	return 0;
}