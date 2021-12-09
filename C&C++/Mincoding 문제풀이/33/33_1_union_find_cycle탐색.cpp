#include <iostream>

using namespace std;

int arr[100];

char FindBoss(char target) {
	if (arr[target] == 0) return target; // 내가 보스
	char boss = FindBoss(arr[target]); // 따라 들어가기
	arr[target] = boss;
	return boss;
}

bool SetUnion(char a, char b) {
	int aboss = FindBoss(a);
	int bboss = FindBoss(b);
	if (aboss == bboss) return false; // 이미 보스가 같다면 사이클이 생성됨 -> 실패
	arr[bboss] = aboss;
	return true;
}

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		char a, b;
		cin >> a >> b;
		if (!SetUnion(a, b)) {
			cout << "발견";
			return 0;
		};
	}
	cout << "미발견";

	return 0;

}