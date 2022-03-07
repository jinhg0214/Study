/* 
그리디 문제에서는 화폐의 단위에서 큰 단위가 작은 단위의 배수였다면,
DP 문제는 배수가 아님!

점화식
	a_(i-k) 를 만드는 방법이 존재하는 경우 : a_i = min(a_i, a_(i-k) +1)
	a_(i-k) 를 만드는 방법이 존재하지 않는 경우 : a_i = INF
*/
#include <iostream>
#include <string.h>

using namespace std;

int d[1001]; // INF로 초기화

int main() {
	int n, m;
	cin >> n >> m;

	memset(d, 0x7f, sizeof(d));

	int arr[101]; // 화폐의 단위를 저장하는 배열

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	d[0] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = arr[i]; j < m + 1; j = j+arr[i]) {
			if (d[j - arr[i]] != 21e8) { // i-k 를 만드는 방법이 존재한다면
				d[j] = min(d[j], d[j - arr[i]] + 1);
			}
		}
	}

	if (d[m] == 21e8) {
		cout << -1;
	}
	else {
		cout << d[m];
	}


	return 0;
}