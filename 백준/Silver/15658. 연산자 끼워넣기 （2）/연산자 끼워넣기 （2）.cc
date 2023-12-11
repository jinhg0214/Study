#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v;
vector<int> oper(4);

int min_val = 21e8;
int max_val = -21e8;

void recursive(int level, int result) {
	if (level == N - 1) {
		min_val = min(min_val, result);
		max_val = max(max_val, result);
		return;
	}

	if (oper[0]) {
		oper[0]--;
		recursive(level + 1, result + v[level + 1]);
		oper[0]++;
	}
	if (oper[1]) {
		oper[1]--;
		recursive(level + 1, result - v[level + 1]);
		oper[1]++;
	}
	if (oper[2]) {
		oper[2]--;
		recursive(level + 1, result * v[level + 1]);
		oper[2]++;
	}
	if (oper[3]) {
		oper[3]--;
		recursive(level + 1, result / v[level + 1]);
		oper[3]++;
	}

	return;
}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> oper[i];
	}

	recursive(0, v[0]);

	cout << max_val << endl;
	cout << min_val << endl;

	return 0;
}

/*
N(2 ≤ N ≤ 11)
둘째 줄에는 A1, A2, ..., AN이 주어진다. (1 ≤ Ai ≤ 100)
셋째 줄에는 합이 N-1인 4개의 정수가 주어지는데, 차례대로 덧셈(+)의 개수, 뺄셈(-)의 개수, 곱셈(×)의 개수, 나눗셈(÷)의 개수

연산자를 어떻게 끼워넣어도 항상 -10억보다 크거나 같고, 10억보다 작거나 같은 결과가 나오는 입력만 주어진다
또한, 앞에서부터 계산했을 때, 중간에 계산되는 식의 결과도 항상 -10억보다 크거나 같고, 10억보다 작거나 같다
-> int형으로 처리 가능
*/