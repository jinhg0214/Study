// https://pro.mincoding.co.kr/problem/G5LV31_%EC%A3%BC%EC%B0%A8%EC%9A%94%EA%B8%88%EC%A0%80%EB%A0%B4%ED%95%9C%EA%B3%B3

#include <iostream>

using namespace std;

int main() {

	int carSize;

	cin >> carSize;

	int parking[9] = { 1,2,3,3,5,1,0,1,3 };

	int sum = 0;
	for (int i = 0; i < carSize; i++) {
		sum += parking[i];
	}

	int min = 21e8;


	for (int i = 0; i <= 9 - carSize; i++) {
		if (min > sum) {
			min = sum;
		}
		sum -= parking[i];
		sum += parking[i + carSize];
	}

	cout << min;

	return 0;
}