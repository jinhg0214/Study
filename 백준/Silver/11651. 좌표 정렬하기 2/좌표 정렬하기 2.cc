#include <iostream>
#include <algorithm>

using namespace std;

int N;
struct point {
	int x;
	int y;
} arr[100005];

// sort 함수에 사용하는 compare를 구조체 밖으로 뺀 버전
bool compare(point p1, point p2) {
	// 1. y 좌표 기준 오름차순
	if (p1.y < p2.y) return true;
	if (p1.y > p2.y) return false;

	// 2. x 좌표 기준 오름차순
	return p1.x < p2.x;
}

int main() {
	// freopen_s(new FILE*, "sample_input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].x >> arr[i].y;
	}

	sort(arr, arr + N, compare);

	for (int i = 0; i < N; i++) {
		cout << arr[i].x << " " << arr[i].y << '\n';
	}

	return 0;
}