#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	// freopen_s(new FILE*, "test.txt", "r", stdin);

	vector<string> vect(5);
	
	for (int i = 0; i < 5; i++) {
		cin >> vect[i];
	}

	int line1, line2;

	cin >> line1 >> line2;

	//line1 정렬
	sort(vect[line1].begin(), vect[line1].end(), less<char>());
	//line2 정렬
	sort(vect[line2].begin(), vect[line2].end(), less<char>());

	// 아랫줄들 출력
	for (int i = 0; i < 5; i++) {
		cout << vect[i][0] << " ";
	}

	return 0;
}