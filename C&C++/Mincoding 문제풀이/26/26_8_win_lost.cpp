#include <iostream>

using namespace std;

int path[4];

void PrintResult() {
	int win = 0, lose = 0;
	for (int i = 0; i < 3; i++) {
		if (path[i] == 1) {
			win++;
		}
		else {
			lose++;
		}

	}

	if (lose == 0) {
		cout << win << "승";
	}
	else if (win == 0) {
		cout << lose << "패";
	}
	else {
		cout << win << "승" << lose << "패";
	}

	
	cout << "(";
	for (int i = 0; i < 3; i++) {
		if (path[i] == 1) {
			cout << "승";
		}
		else if (path[i] == 2) {
			cout << "패";
		}
	}
	cout << ")" << endl;

	return;
}

void game(int lv) {
	
	if (lv == 3) {
		
		PrintResult();

		return;
	}

	for (int x = 1; x <= 2; x++) {
		path[lv] = x;
		game(lv + 1);
		path[lv] = 0;

	}

}

int main() {
	
	game(0);

	return 0;
}