#include <iostream>

#define MAX 2010

using namespace std;

int main() {
	// freopen_s(new FILE*, "sample_input.txt", "r", stdin);

	int N, tmp;
	int arr[MAX] = { 0 };

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (arr[tmp+1000] == 1) continue;
		arr[tmp+1000] = 1;
	}

	for (int i = 0; i < MAX; i++) {
		if (arr[i] == 1) cout << i-1000 << " ";
	}

	return 0;
}

// -1000 <= 0 <= +1000 에 1000씩 더해서 0 <= 1000 <= 2000 으로 매핑
 