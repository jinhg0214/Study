#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	// freopen_s(new FILE*, "sample_input.txt", "r", stdin);
	
	int K, num;
	cin >> K;
	for (int i = 1; i <= K; i++) {
		cin >> num;
		int max = 0, min = 21e8, score[51] = { 0 };
		for (int j = 0; j < num; j++) {
			int tmp;
			cin >> tmp;
			score[j] = tmp;
			if (tmp > max) max = tmp;
			if (tmp < min) min = tmp;
		}

		sort(score, score + num);
		int max_diff = 0;
		for (int j = 0; j < num - 1; j++) {
			if (max_diff < score[j+1] - score[j]) {
				max_diff = score[j+1] - score[j];
			}
		}

		int de = -1;

		printf("Class %d\nMax %d, Min %d, Largest gap %d\n", i, max, min, max_diff);
	}

	

	return 0;
}