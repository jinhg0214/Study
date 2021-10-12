// Lv 4, br n 인 재귀

#include <iostream>

using namespace std;

int path[10];

void clean(int Lv, int n) {

	if (Lv == 4) {
		for (int i = 0; i < Lv; i++) {
			cout << path[i];
		}
		cout << endl;
		return;
	}

	for (int x = 1; x <= n; x++) {
		path[Lv] = x; // x번째 친구가 청소 
		clean(Lv + 1, n);
		path[Lv] = 0; 
	}

}

int main() {
	int n;

	cin >> n;

	clean(0, n);

	return 0;
}