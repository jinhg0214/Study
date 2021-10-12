#include <iostream>

using namespace std;

int main() {
	int a[4], a_idx=0;
	int b[4], b_idx=0;

	// 입력받기
	for (int i = 0; i < 4; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> b[i];
	}

	int result[8], r_idx = 0;

	// 각 배열의 인덱스들을 비교하면서 res에 삽입한다
	while (1) {
		if (a[a_idx] < b[b_idx]) {
			result[r_idx] = a[a_idx];
			r_idx++;
			a_idx++;
		}
		else {
			result[r_idx] = b[b_idx];
			r_idx++;
			b_idx++;
		}
		if (a_idx == 4 || b_idx == 4) break; // 누군가 끝난 경우 
	}
		
	// 남은거 짬처리
	// a가 남은경우
	while (a_idx < 4) {
		result[r_idx] = a[a_idx];
		r_idx++;
		a_idx++;
	}
	// b가 남은경우
	while (b_idx < 4) {
		result[r_idx] = b[b_idx];
		r_idx++;
		b_idx++;
	}

	for (int i = 0; i < r_idx; i++) {
		cout << result[i] << " ";
	}

	return 0;
}