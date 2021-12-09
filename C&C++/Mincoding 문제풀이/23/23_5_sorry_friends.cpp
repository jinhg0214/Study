#include <iostream>

using namespace std;

char friends[6] = "EWABC";
char path[5];
bool used[5];


void rollercoaster(int Lv) {
	if (Lv == 4) {
		cout << path << endl;
		return;
	}

	for (int x = 0; x < 4; x++) {
		if (used[x] == 1)continue;

		path[Lv] = friends[x];
		used[x] = 1;

		rollercoaster(Lv + 1);

		path[Lv] = 0;
		used[x] = 0;
	}
}

int main() {
	char ch;

	cin >> ch;

	// 제외할 친구를 입력받고, 문자열 재생성
	int i;
	for (i = 0; i < 5; i++) {
		if (ch == friends[i]) {
			for (int j = i; friends[j] != '\0'; j++) {
				friends[j] = friends[j + 1];
			}
		}
	}
	friends[i] = '\0';

	// 제외한 친구들끼리 순서 정하기
	rollercoaster(0);

	return 0;
}