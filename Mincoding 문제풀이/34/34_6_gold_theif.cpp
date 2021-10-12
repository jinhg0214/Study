#include <iostream>
#include <queue>

using namespace std;

struct node {
	int n;
	int type;
};

int n;
priority_queue<node> q; // min heap

bool operator<(node back, node front) {
	return front.n < back.n;
}

void Input() {
	freopen_s(new FILE*, "test.txt", "r", stdin);
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int goldVal;
		cin >> goldVal;
		q.push({ goldVal, 0 }); // 처음엔 금이므로 모두 타입을 0으로 
	}

}

int main() {
	
	Input();

	int cnt = 0;
	while (1) {
		// 황금 두개 꺼내고
		node now = q.top();
		q.pop();
		if (now.type == 1) break;
		cnt++;

		now = q.top();
		q.pop();
		if (now.type == 1) break;
		cnt++;
		// 돌 하나 넣기
		q.push({ now.n*2, 1 });

	}

	cout << cnt;

	return 0;
}