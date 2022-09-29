#include <iostream>

using namespace std;

int main() {
	// freopen_s(new FILE*, "sample_input.txt", "r", stdin);
	
	int tmp, sum = 0;
	int arr[101] = { 0 }; // 1000보다 작은 10의 배수들만 저장되므로 10 -> 1, 20 -> 2 로 카운트
	

	for (int i = 0; i < 10; i++) {
		cin >> tmp;
		sum += tmp;
		arr[tmp / 10]++;
	}
	int max = 0, idx = 0;
	for (int i = 0; i < 101; i++) {
		if (max < arr[i]) {
			max = arr[i];
			idx = i;
		}
	}

	cout << sum / 10 << '\n' << idx * 10;

	return 0;
}