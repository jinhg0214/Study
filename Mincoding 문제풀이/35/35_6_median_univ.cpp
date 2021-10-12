#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	freopen_s(new FILE*, "test.txt", "r", stdin);
	int n;
	cin >> n;
	
	vector<int> vect = { 500 };

	while (n--) {
		int score1, score2;
		cin >> score1 >> score2;

		vect.push_back(score1);
		vect.push_back(score2);

		sort(vect.begin(), vect.end(), less<int>()); // 오름차순으로 정렬

		int mid = (0 + vect.size()-1) / 2;

		cout << vect[mid] << endl;
	}
	
	return 0;
}