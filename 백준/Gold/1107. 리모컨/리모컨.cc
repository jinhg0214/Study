#include <bits/stdc++.h>

using namespace std;

bool button_broken[10]; // true : 고장

// num 채널을 숫자로 만들 수 있는지 체크하는 함수
bool check(int num) {
	string str = to_string(num);
	for (int i = 0; i < str.size(); i++) {
		// str[i] 라는 숫자가 고장난 숫자가 라면 불가능 리턴
		if (button_broken[str[i] - '0'] == true) {
			return false;
		}
	}
	return true;
}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	int cur = 100, target;
	cin >> target;

	int M; cin >> M;
	for (int i = 0; i < M; i++) {
		int tmp; cin >> tmp;
		button_broken[tmp] = true;
	}

	// 1. +, -로 이동
	int cnt = abs(cur - target);

	// 2. 0~100만까지 채널을 누를 수 있는지 체크
	for (int i = 0; i <= 1000000; i++) {
		if (check(i)) {
			// 채널 i로 이동이 가능한 경우
			// i로 이동해서 +, -로 이동하는 회수만큼 추가 후 최소값 비교
			
			int pressed = to_string(i).size(); // 버튼 누른 회수는 i의 자리수 만큼임
			int diff = abs(target - i);

			cnt = min(cnt, pressed + diff);
		}
	}

	cout << cnt;

	return 0;

	/*
	왜 100만까지 채널을 누를 수 있는지 체크하는게 이해하기 어려움. N은 0에서 50만인데??

- 채널은 무한하다고 주어져있음

- 1234567890 이 고장 난 경우, 100번에서 시작, 목표 채널이 500,000인 경우는 올라가는게 499,900번으로 빠름

- 그러나 위에서 아래로 내려오는게 더 빠른 경우가 존재

- 12345 789 만 고장나고, 6과0은 멀쩡한 경우, 목표 채널이 500,000인 경우는 600,000에서 내려오는게 10만번으로 499,000번보다 빠르다

- 즉, 채널 N으로 이동하기 위해서 50만보다 높은 채널에서 내려오는 경우가 존재할 수 있음

- 그러므로, 50만 이상에서도 시도해야함

*/
}

