#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	// freopen_s(new FILE*, "sample_input.txt", "r", stdin);

	int dwarf[9];
	int sum = 0;

	for (int i = 0; i < 9; i++) {
		cin >> dwarf[i];
		sum += dwarf[i];
	}

	// 키순으로 정렬
	sort(dwarf, dwarf + 9);

	int idx1, idx2;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (sum - dwarf[i] - dwarf[j] == 100) {
				idx1 = i;
				idx2 = j;
			}
		}
	}

	// 오름차순으로 정렬
	for(int i=0; i<9; i++){
		if (i == idx1 || i == idx2) continue;
		cout << dwarf[i] << endl;
	}

	return 0;
}