#include <iostream>
#include <algorithm>

using namespace std;

int dwarf[9];
int fake_dwarf[2];

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	int total = 0;
	for (int i = 0; i < 9; i++) {
		cin >> dwarf[i];
		total += dwarf[i];
	}

    // 모든 난쟁이들의 키를 더해놓고 두명을 빼본다.
	for (int i = 0; i < 9; i++) {
		for (int j = i+1; j < 9; j++) {
			if ((total - (dwarf[i] + dwarf[j])) == 100) {
				fake_dwarf[0] = i;
				fake_dwarf[1] = j;
			}
		}
	}

	for (int i = 0; i < 9; i++) {
		if (i == fake_dwarf[0] || i == fake_dwarf[1]) continue;
		cout << dwarf[i] << endl;
	}

	return 0;
}