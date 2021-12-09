#include <iostream>

using namespace std;

int table[7][2] = {
		3,1,
		2,1,
		1,0,
		3,1,
		2,0,
		-1,-1,
		1,0,
};

void trace(int n) {
	
	if (table[n][0] == -1) {
		cout << n << "번" << endl;
		return;
	}

	
	if (table[n][1] == 1) {
		trace(n+ table[n][0]);
	}
	else if (table[n][1] == 0) {
		trace(n - table[n][0]);
	}
	cout << n << "번" << endl;
}

int main() {
	

	int n;
	cin >> n;

	trace(n);

	return 0;
}