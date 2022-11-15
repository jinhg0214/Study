#include <iostream>

using namespace std;

int main() {
	// freopen_s(new FILE*, "sample_input.txt", "r", stdin);
	int score[5] = { 0 };

	for (int i = 0; i < 5; i++) {
		int tmp = 0;
		for (int j = 0; j < 4; j++) {
			cin >> tmp;
			score[i] += tmp;
		}
	}
	int max_num = -1, winner = -1;
	for (int i = 0; i < 5; i++) {
		if (score[i] > max_num) {
			winner = i;
			max_num = score[i];
		}
	}

	cout << winner + 1 << " " << max_num << '\n';

	return 0;
}