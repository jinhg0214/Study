#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int arr[5];

int main() {

	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}

	// algorithm 라이브러리의 순열 함수(next_permutation)를 사용하기 위해 정렬
	sort(arr, arr + 5);

	int min_val = 21e8;

	// 3개를 뽑아 이 수들의 최소공배수를 구한다
	do {
		int lcm_val = lcm(arr[0], arr[1]); // 최소 공배수는 numeric 라이브러리의 lcm 함수를 이용했음
		lcm_val = lcm(lcm_val, arr[2]);
		
		min_val = min(min_val, lcm_val);
	} while (next_permutation(arr, arr + 5));

	cout << min_val;

	return 0;
}
