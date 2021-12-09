#include <iostream>

using namespace std;

int main() {
	// freopen("test.txt", "r", stdin);

	int arr[8];

	// 가장 왼쪽에 있는 수가 피벗
	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
	}

	int pivot = arr[0];
	int a=1, b=7;
	int tmp;

	// a와 b가 엇갈릴때까지 반복
	while (a <= b) {

		// 왼쪽에서부터 오른쪽으로 pivot 보다 큰 수 찾기
		for (int i = a; i < 8; i++) {
			if (arr[i] > pivot) {
				a = i;
				break;
			}
		}

		// 오른쪽에서 왼쪽으로 pivot보다 작은 수 찾기
		for (int i = b; i >= 0; i--) {
			if (arr[i] < pivot) {
				b = i;
				break;
			}
		}

		if (a > b) {
			break;
		}

		// 큰수와 작은 수를 swap
		tmp = arr[a];
		arr[a] = arr[b];
		arr[b] = tmp;

	}
	
	// 반복문을 빠져 나왔다면 PIVOT과 B를 바꿔준다
	tmp = arr[0];
	arr[0] = arr[b];
	arr[b] = tmp;
	

	for (int i = 0; i < 8; i++) {
		cout << arr[i] << " ";
	}
	

	return 0;
}