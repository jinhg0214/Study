#include <iostream>

using namespace std;

char path[10];

void go(int Lv) {
	if (Lv == 2) {
		for (int i = 0; i < Lv; i++) {
			cout << path[i];
		}
		cout << endl;
		return;
	}

	for (char x = 'A'; x <= 'C'; x++) {
		path[Lv] = x;

		go(Lv + 1);

		path[Lv] = 0;
	}
}

int main() {

	go(0);

	return 0;
}