#include <iostream>
#include <string>

using namespace std;

string STS = "BTSKR";

char path[5];
bool used[5];

int n, cnt = 0;

void subgroup(int Lv) {

	if (Lv == n) {
		// 결성된 조합중 S가 없으면 출력안함
		// 방법1. path에 S가 있는지 확인
		/*bool flag = 0;
		for (int i = 0; i < Lv; i++) {
			if (path[i] == 'S') {
				flag = 1;
				break;
			}
		}*/
		// 방법2. used에 S가 사용되었는지 확인
		if (used[2] == 1) {
			cnt++;
		}
		
		return;
	}

	for (int x = 0; x < 5; x++) {
		if (used[x] == 1)continue;
		path[Lv] = STS[x];
		used[x] = 1;
		subgroup(Lv + 1);

		path[Lv] = 0;
		used[x] = 0;
		
	}
}

int main() {
	cin >> n;

	subgroup(0);

	cout << cnt;

	return 0;
}