#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> lotto; // 선택한 번호 6개를 저장하는 배열

// a : 입력으로 주어진 수의 배열
// index : 선택할지 말지 결정해야 하는 인덱스
// cnt : 현재까지 포함된 개수
void go(vector<int> & a, int index, int cnt) {

	// case1 : 정답을 찾은경우 (6개를 고른경우)
	if (cnt == 6) { 
		for (int num : lotto) {
			printf("%d ", num);
		}
		cout << '\n';
		return;
	}

	// case2 : 불가능한 경우
	if (index >= a.size()) { // 더이상 선택할 수가 없는 경우
		return;
	}

	// case3 : 다음 경우
	// 1) 인덱스를 포함하여 다음 경우 호출
	lotto.push_back(a[index]); // 수를 선택했으므로 lotto 배열에 추가
	go(a, index + 1, cnt + 1);
	lotto.pop_back();	// 다음 경우를 위해 index번째를 선택한 경우는 lotto에서 뺌

	// 2) 선택하지 않고 다음 경우 호출
	go(a, index + 1, cnt);

}

int main() {

	while (true) {
		int k; // 개수

		cin >> k;
		if (k == 0) {
			break;
		}

		vector<int> s(k);

		for (int i = 0; i < k; i++) {
			cin >> s[i];
		}

		// 사전순으로 출력을 위해 정렬
		sort(s.begin(), s.end());

		go(s, 0, 0);

		cout << '\n';
	}

	return 0;
}