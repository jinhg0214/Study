// 방법 1. 완전 탐색으로 더했을 때 값이 100인 드워프를 찾는다
#include <iostream>
#include <algorithm>

using namespace std;

int height[10];
int used[10] = { 0 };
bool flag = false;

void abc(int level, int sum) {
	if (flag == true) return; // 이미 답을 찾았으면 가지치기
	if (sum > 100) return; // 100을 초과하면 더이상 살펴보지 않음

	if (level == 7) { // 7명을 골랐다면 100인지 확인하고 출력함
		if (sum == 100) {
			for (int i = 0; i < 9; i++) {
				if (used[i] == 1) {
					cout << height[i] << endl;
				}
			}
			flag = true;
		}
		return;
	}
	
	for (int i = level; i < 9; i++) {
		if (used[i] == 1) continue;
		used[i] = 1;
		abc(level + 1, sum + height[i]);
		used[i] = 0;
	}
	return;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	for (int i = 0; i < 9; i++) {
		cin >> height[i];
	}
	sort(height, height + 9);
	abc(0, 0);

	return 0;
}

// 방법 2. 모든 난쟁이들의 키를 더한뒤 두명을 빼본다. 얘도 완전탐색이지만 이쪽이 더 빠를듯

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

	// 두 사기 드워프를 제외하고 나머지 진짜만 출력. 이미 오름차순으로 정렬되어있음
	for (int i = 0; i < 9; i++) {
		if (i == idx1 || i == idx2) continue;
		cout << dwarf[i] << endl;
	}

	return 0;
}