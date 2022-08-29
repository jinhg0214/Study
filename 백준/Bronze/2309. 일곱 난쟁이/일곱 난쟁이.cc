#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int dwarf[9];

	int sum = 0;

	for (int i = 0; i < 9; i++) {
		cin >> dwarf[i];
		sum += dwarf[i];
	}

	// 키순으로 정렬
	sort(dwarf,dwarf+9);

	int index1, index2;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (i != j && (sum - dwarf[i] - dwarf[j] == 100)) {
				index1 = i;
				index2 = j;
			}
		}
	}

	// index1,2 를 제외한 모두 출력
	for (int i = 0; i < 9; i++) {
		if (i != index1 && i != index2) {
			cout << dwarf[i] << endl;
		}
	}



}