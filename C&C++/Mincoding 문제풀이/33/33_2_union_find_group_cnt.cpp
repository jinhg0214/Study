#include <iostream>

using namespace std;

int arr[200];

char FindBoss(char target) {
	// 소속하지 않은 경우
	if (arr[target] == 0) return target;

	// 소속한 경우
	char boss = FindBoss(arr[target]);
	arr[target] = boss;
	return boss;
}

void SetUnion(char a, char b) {
	int aboss = FindBoss(a);
	int bboss = FindBoss(b);

	if (aboss == bboss) return;
	arr[bboss] = aboss;
}

void Init() {
	SetUnion('A', 'B');
	SetUnion('A', 'C');

	SetUnion('D', 'E');
	SetUnion('E', 'F');

	SetUnion('G', 'H');

	SetUnion('I', 'J');
}

int main() {
	// freopen_s(new FILE*, "test.txt", "r", stdin);

	Init();

	int n;
	cin >> n;

	int cnt = 4; // 현재 그룹 개수

	for (int i = 0; i < n; i++) {
		char a, b;
		cin >> a >> b;
		if (FindBoss(a) != FindBoss(b)) {
			SetUnion(a, b);
			cnt--;
		}
	}

	cout << cnt << "개";

	// 



	return 0;
}