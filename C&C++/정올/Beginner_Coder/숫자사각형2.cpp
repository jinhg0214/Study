/*
1 2 3 4 5
10 9 8 7 6 5
11 12 13 14 15
20 19 18 17 16
21 22 23 24 25 ㄹ 자로 출력하기
*/

#include <iostream>

using namespace std;

int main() {
	int n, m, idx = 1;
	int arr[101][101] = { 0 };

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		// 앞에서부터
		if (i % 2 == 0) {
			for (int j = 0; j < m; j++) {
				arr[i][j] = idx;
				idx++;
			}
		}
		
		// 뒤에서 부터
		else {
			for (int j = m - 1; j >= 0; j--) {
				arr[i][j] = idx;
				idx++;
			}
		}
	}

	/*
	직접 출력하려면 상당히 복잡해지므로, 다른 배열에 저장한 뒤 출력하는게 편하다
	*/

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}