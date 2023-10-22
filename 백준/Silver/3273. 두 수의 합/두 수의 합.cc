#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);

	int arr[100005];
	int N, X;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cin >> X;
	
	sort(arr, arr + N);

	int sum = 0, cnt = 0, left = 0, right = N - 1;
	while (1) {
		if (left >= right) break;
		sum = arr[left] + arr[right];
		// 합이 큰 경우, 오른쪽 포인터를 한칸 앞으로
		if (sum > X) 
			right--;
		// 합이 작은 경우, 왼쪽 포인터를 한칸 뒤로
		else if (sum < X) 
			left++;
		// 타겟값인 경우, 오른쪽 포인터를 한칸 앞으로, 왼쪽 포인터를 한칸 뒤로 
		else {
			right--;
			left++;
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}

/* 
# 1. 2중 For문을 돌리면 시간초과!
	```
	int sum = 0, cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			if (i == j) continue;
			sum = arr[i] + arr[j];
			if (sum == X) cnt++;
		}
	}
	```
# 2. 투포인터로 접근
### 알고리즘
1. 배열을 정렬시키고
2. 왼쪽, 오른쪽 포인터로 접근
3. sum = left + right 값이 target보다 크면 right--, target보다 작으면 left++;
4. 두 포인터가 만나면 while문 종료
*/