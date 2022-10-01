#include <iostream>
#include <algorithm>

using namespace std;

struct node {
	int x;
	int y;
	
	bool operator<(const node &n2) {
		if (this->x < n2.x) return true;
		if (this->x > n2.x) return false;
		return this->y < n2.y;
	}
};


int main() {
	// freopen_s(new FILE*, "sample_input.txt", "r", stdin);
	
	int n;
	node arr[100005];

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].x, &arr[i].y);
	}

	sort(arr, arr + n); // 별도로 함수 지정 안해줘도 오버로딩된 연산자 < 를 사용함

	for (int i = 0; i < n; i++) {
		printf("%d %d\n", arr[i].x, arr[i].y);
	}
	

	return 0;
}