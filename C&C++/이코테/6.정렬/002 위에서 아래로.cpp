/*
수열을 입력받고 이를 내림차순으로 출력하는 프로그램
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> vec;

	for (int i = 0; i < N ;i++) {
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}

	sort(vec.begin(), vec.end(), greater<int>());

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;

	return 0;
}