#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
    // 1. 입력받기
	int N;	cin >> N;
	deque<int> order;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		order.push_back(tmp);
	}
    // 2. 입력 순서를 뒤집는다
	reverse(order.begin(), order.end());

	deque<int> origin;

	int card = 1;
	for(int i=0; i<N; i++){
        // 1. 현재 순서의 카드를 맨 위로 올린다
		if (order[i] == 1) {
			origin.push_front(card);
			card++;
		}
        // 2. 현재 순서의 카드를 위에서 두번째에 넣는다 
		else if (order[i] == 2) {
			// 두번째에 카드 넣기
			int tmp = origin.front();
			origin.pop_front();
			origin.push_front(card);
			origin.push_front(tmp);
			card++;
		}
        // 3. 현재 순서의 카드를 제일 아래에 넣는다
		else if (order[i] == 3) {
			origin.push_back(card);
			card++;
		}
	}

	for (auto it : origin) {
		cout << it << " ";
	}

	return 0;
}