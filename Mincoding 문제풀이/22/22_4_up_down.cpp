#include <iostream>
#include <string>

using namespace std;

int main(){
	string cmd;
	int lv = 1;

	for (int i = 0; i < 5; i++) {
		cin >> cmd;

		if (cmd == "up") {
			lv++;
		}
		else if (cmd == "down") {
			lv--;
		}
	}

	if (lv == 0){
		cout << "B1";
	}
	else if (lv < 0) {
		cout << "B" << abs(lv) + 1;
	}
	else {
		cout << lv;
	}

	return 0;
}