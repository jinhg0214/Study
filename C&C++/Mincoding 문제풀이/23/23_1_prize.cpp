// Lv3, br4인 문제

#include <iostream>

using namespace std;

char name[5];
char path[4];
bool used[5]; 

void prize(int Lv) {

	if (Lv == 3) {
		for (int i = 0; i < Lv; i++) {
			cout << path[i];
		}
		cout << endl;
		return;
	}

	for (int x = 0; x < 4; x++) {
		
		if (used[x] == 1) continue; // 이미 상을 받은경우

		path[Lv] = name[x];
		used[x] = 1;

		prize(Lv + 1);

		path[Lv] = 0;
		used[x] = 0;
	}

}


int main() {

	cin >> name;

	prize(0);

	return 0;
}