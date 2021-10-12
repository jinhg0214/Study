#include <iostream>
#include <string>

using namespace std;

int n;
int population[10];
int arr[100];

void Input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> population[i];
	}
}

char FindBoss(char target) {
	if (arr[target] == 0) return target;
	char boss = FindBoss(arr[target]); 
	arr[target] = boss;
	return boss;
}

void SetUnion(char a, char b) {
	char aboss = FindBoss(a);
	char bboss = FindBoss(b);
	if (aboss == bboss)return;
	arr[bboss] = aboss;
}

void War(char a, char b) {
	// 각 동맹수 확인
	int ateam = 0, bteam = 0;

	for (char x = 'A'; x <= (char)('A'+n); x++) {
		if (FindBoss(x) == FindBoss(a)) {
			ateam += population[x - 'A'];
		}
		else if (FindBoss(x) == FindBoss(b)) {
			bteam += population[x - 'A'];
		}
	}

	// 진쪽은 인구수 0으로
	if (ateam > bteam) {
		for (char x = 'A'; x <= (char)('A' + n); x++) {
			if (FindBoss(x) == FindBoss(b)) {
				population[x - 'A'] = 0;
			}
		}
	}
	else {
		for (char x = 'A'; x <= (char)('A' + n); x++) {
			if (FindBoss(x) == FindBoss(a)) {
				population[x - 'A'] = 0;
			}
		}
	}
}

int main() {
	freopen_s(new FILE*, "test.txt", "r", stdin);

	Input();

	int T;
	cin >> T;

	while (T--) {
		string situation;
		char a, b;
		cin >> situation >> a >> b;

		if (situation == "alliance") {
			SetUnion(a, b);
		}
		else {
			War(a, b);
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (population[i] != 0) {
			cnt++;
		}
	}
	cout << cnt;


	return 0;
}