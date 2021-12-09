#include <iostream>

using namespace std;

int main() {
	int N, K, cnt = 0;
	int target;
	cin >> N >> K;

	while (1) {
		// N을 K로 나누어질때까지 일단 1을 뺀다
		target = (N / K) * K; // 효율적으로 한번에 빼주는 방식
		cnt += (N - target);  
		N = target;

		// N이 K보다 작으면 탈출조건
		if (N < K) {
			break;
		}

		cnt++;
		N = N / K;
	}
	// 마지막으로 남은 수에 대해 1씩 빼기
	cnt = cnt + (N - 1); 
	cout << cnt;
	
	return 0;
}
/*
내 풀이 : 재귀를 이용해서 완전탐색했음
#include <iostream>

using namespace std;

int N, K;
int min_cnt = 21e8;

void run(int lev, int num) {
	// 바닥조건 : N==1이면 최소값 비교 후 갱신후 탈출
	if (num == 1) {
		if (min_cnt > lev) {
			min_cnt = lev;
		}
		return;
	}

	run(lev + 1, num - 1);

	if (num / 4 != 0) {
		run(lev + 1, num / 4);
	}
	else {
		return;
	}


}

int main() {
	N = 25;
	K = 5;

	run(0, N);

	cout << min_cnt;

	return 0;
}

책 풀이 : 그리디를 이용해 최대한 많이 나눈 후 빼기 실행
*/