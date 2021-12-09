#include <iostream>

using namespace std;

int n;
int arr[100];
int map[5][5];

int FindBoss(int target) {
	if (arr[target] == 0) return target;
	int boss = FindBoss(arr[target]);
	arr[target] = boss;
	return boss;
}

bool SetUnion(int a, int b) {
	int aboss = FindBoss(a);
	int bboss = FindBoss(b);
	if (aboss == bboss) return false; // 안넣고 리턴
	arr[bboss] = aboss;
	return true;
}

void Input() {
	cin >> n;
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			cin >> map[y][x];
		}
	}
}

int main() {

	Input();

	// 무방향 간선이므로 한쪽만 참조한다
	for (int y = 0; y < 5; y++) {
		for (int x = y+1; x < 5; x++) {
			if (map[y][x] == 1) {
				if (!SetUnion(y, x)) {
					cout << "cycle 발견";
					return 0;
				}
			}
		}
	}
	cout << "미발견";

	return 0;
}