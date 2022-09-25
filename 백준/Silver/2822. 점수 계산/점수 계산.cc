#include <iostream>
#include <algorithm>

using namespace std;

int score[8];
int chk[8] = { 0 };

int main() {
	// freopen_s(new FILE*, "sample_input.txt", "r", stdin);
	for (int i = 0; i < 8; i++) {
		cin >> score[i];
	}

	// 뒤에서 3등 체크
	int min_score[3] = { 999,999,999 };

	for (int i = 0; i < 8; i++) {
		if (score[i] < min_score[0] && chk[i] == 0) {
			min_score[0] = score[i];
		}
	}
	for (int i = 0; i < 8; i++) {
		if (score[i] == min_score[0]) {
			chk[i] = 1;
			break;
		}
	}

	for (int i = 0; i < 8; i++) {
		if (score[i] < min_score[1] && chk[i] == 0) {
			min_score[1] = score[i];
		}
	}
	for (int i = 0; i < 8; i++) {
		if (score[i] == min_score[1]) {
			chk[i] = 1;
			break;
		}
	}

	for (int i = 0; i < 8; i++) {
		if (score[i] < min_score[2] && chk[i] == 0) {
			min_score[2] = score[i];
		}
	}
	for (int i = 0; i < 8; i++) {
		if (score[i] == min_score[2]) {
			chk[i] = 1;
			break;
		}
	}

	int sum = 0;
	for (int i = 0; i < 8; i++) {
		if (chk[i] == 0) {
			sum += score[i];
		}
	}
	cout << sum << endl;
	for (int i = 0; i < 8; i++) {
		if (chk[i] == 0) {
			cout << i+1 << " ";
		}
	}

	return 0;
}