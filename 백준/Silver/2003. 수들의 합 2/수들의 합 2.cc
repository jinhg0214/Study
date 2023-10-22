#include <iostream>

using namespace std;

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);

	int N, M;
	int arr[10001];
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	// 투 포인터 사용

	int start = 0, end = 0;
	int sum = arr[0], cnt = 0;

	while (end < N) {
		// 합이 작은 경우, end를 이동
		if (sum < M) {
			end++;
			// end가 범위 내라면, sum 증가
			if (end < N) {
				sum += arr[end];
			}
		}
		// 합이 큰 경우, start 이동
		else if (sum > M) {
			sum -= arr[start];
			start++;
		}
		// 합이 M이라면, start, end 증가, cnt 증가
		else if (sum == M) {
			sum -= arr[start];
			start++;
			end++;
			if (end < N) {
				sum += arr[end];
			}
			cnt++;
		}
		
	}

	cout << cnt;

	return 0;
}