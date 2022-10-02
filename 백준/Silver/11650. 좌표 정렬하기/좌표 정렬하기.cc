#include <iostream>
#include <algorithm> 

using namespace std;

struct node {
	int x;
	int y;
};

// 비교 함수를 구현
bool compare(node front, node back) {
	if (front.x < back.x) return true;
	if (front.x > back.x) return false;
	return front.y < back.y;
}

int main() {
	// freopen_s(new FILE*, "sample_input.txt", "r", stdin);
	
	int n;
	node arr[100005];

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].x, &arr[i].y);
	}

	// STL sort 이용
	sort(arr, arr + n, compare);

	for (int i = 0; i < n; i++) {
		printf("%d %d\n", arr[i].x, arr[i].y);
	}
	

	return 0;
}