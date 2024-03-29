#include <iostream>

using namespace std;

int N, K;
int price[11];

int main() {
	// freopen_s(new FILE*, "sample_input.txt", "r", stdin);
	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++) {
		scanf("%d", &price[i]);
	}

	int cnt = 0;
	/* 내 풀이
    for (int i = N - 1; i >= 0; i--) {
		if (K == 0) break;
		while (K > 0) {
			if (K - price[i] >= 0) {
				K = K - price[i];
				cnt++;
			}
			else {
				break;
			}
		}
	}*/
    // 더 좋은 풀이
	for (int i = N - 1; i >= 0; i--) {
		cnt += K / price[i];
		K = K % price[i];
	}
	
	printf("%d", cnt);

	return 0;
}