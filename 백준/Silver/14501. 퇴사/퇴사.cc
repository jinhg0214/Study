#include <iostream>

using namespace std;

/*배열 크기를 21로 설정한 이유는 N이 최대 15까지 들어올 수 있는데, 
 15일에 5일짜리 일을 수주하면 20일까지 검사해야함! + 1*/
int T[21]; // 상담하는데 걸리는 일 수 
int P[21]; // 상담 비용
int n; // 남은 일수
int ans = 0;

void go(int day, int sum) {

	// case2 : 정답인 경우 (퇴사날을 맞춰 일을 받음)
	if (day == n + 1) {
		if (ans < sum) { // sum이 최대값인 경우
			ans = sum;
		}
		return;
	}

	// case1 : 불가능한 경우 (퇴사날 초과)
	if (day > n + 1) return;

	// case3 : 다음 경우 호출
	go(day + 1, sum);				// 상담을 하지 않는 경우
	go(day + T[day], sum + P[day]); // 상담을 하는 경우
}

int main() {

	cin >> n;
	for (int i = 1; i <= n; i++) { /* !!!!!!!!  1일부터 N일 까지 계산해야 하므로, T[1],P[1]부터 입력받아야함!!*/
		scanf("%d %d", &T[i], &P[i]);
	}
	
	go(1,0); // 1일, 0원부터 시작

	cout << ans << '\n';

	return 0;
}