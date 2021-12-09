/*
N*M의 카드 배열이 주어짐.
각 행을 선택 후, 그 행에서 가장 작은 카드를 고른다.
-> 이 중에서 가장 큰 수는?

즉 행의 가장 작은수들중에서 가장 큰 수를 고르는 문제
*/

/* 풀이
처음 입력받을때부터, 그 행의 입력중 가장 작은수만 저장한다.
이후 모든 입력이 끝나면, 가장 작은 수 들 중에서 가장 큰 수를 찾는다.
*/

#include <iostream>

using namespace std;

int N, M;
int Min[101];


void Input() {
	cin >> N >> M;

	for (int y = 0; y < N; y++) {
		int Min_y = 21e8;

		for (int x = 0; x < M; x++) {
			int tmp;
			cin >> tmp;

			if (tmp < Min_y) {
				Min_y = tmp;
			}
		}

		Min[y] = Min_y;
	}

}

int Solution() {
	int Max = 0;

	for (int i = 0; i < N; i++) {
		if (Max < Min[i]) {
			Max = Min[i];
		}
	}

	return Max;
}

int main() {
	freopen_s(new FILE*, "test.txt", "r", stdin);

	Input();

	cout << Solution();

	return 0;
}