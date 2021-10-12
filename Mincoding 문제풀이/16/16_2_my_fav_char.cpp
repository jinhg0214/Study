#include <iostream>

using namespace std;


int main() {
	char arr[4][4] = {
		'A','B','K','T',
		'K','F','C','F',
		'B','B','Q','Q',
		'T','P','Z','F'
	};

	char ch[2];

	cin >> ch[0] >> ch[1];
	
	int cnt=0;

	for (int i = 0; i < 2; i++) {
		for (int y = 0; y < 4; y++) {
			for (int x = 0; x < 4; x++) {
				if (arr[y][x] == ch[i]) {
					cnt++;
				}
			}
		}
	}
	cout << cnt;

	return 0;
}