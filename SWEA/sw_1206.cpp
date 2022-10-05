#include <iostream>
#include <algorithm>

using namespace std;

int N, res = 0;
int map[1005];
int diff[4] = { 0 };

void Input() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &map[i]);
	}
}

int main() {
	freopen_s(new FILE*, "sample_input.txt", "r", stdin);
	
	int T = 1;
	while (T <= 10) {
		int res = 0;
		printf("#%d ", T++);
		
		// input
		Input();

		for (int i = 2; i <= N-3; i++) {
			
			diff[0] = map[i] - map[i-2];
			diff[1] = map[i] - map[i-1];
			diff[2] = map[i] - map[i + 1];
			diff[3] = map[i] - map[i + 2];
 				
			// 음수가 있다면 조망권 침해!
			if (diff[0] < 0 || diff[1] < 0 || diff[2] < 0 || diff[3] < 0) continue;
			res += min(min(diff[0], diff[1]),min(diff[2],diff[3]));
				
		}
		
		printf("%d\n", res);

	}
	int de = -1;

	return 0;
}