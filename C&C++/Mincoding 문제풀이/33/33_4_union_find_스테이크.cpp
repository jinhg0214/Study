#include <iostream>

using namespace std;

int n, k;
int arr[100] = { 0 };

char FindBoss(char target) {
	if (arr[target] == 0) return target;
	char boss = FindBoss(arr[target]);
	arr[target] = boss;
	return boss;
}

bool SetUnion(char a, char b){
	char aboss = FindBoss(a);
	char bboss = FindBoss(b);
	if (aboss == bboss) return false;
	arr[bboss] = aboss;
	return true;
}

int main() {
	freopen_s(new FILE*, "test.txt", "r", stdin);

	cin >> n >> k;

	while (n--) {
		char a, b;
		cin >> a >> b;

		SetUnion(a, b);
	}
	for (char i = '1'; i < '1' + k; i++) {
		for (char j = 'A'; j <= 'F'; j++) {
			if (FindBoss(i) == FindBoss(j)) {
				cout << j;
			}
		}
	}


	return 0;
}