#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	int M, N;
	unsigned int s = 0;
	string cmd;

	cin >> M;
	while (M--) {
		cin >> cmd;
		if (cmd == "add") {
			cin >> N;
			s |= (1 << N); // 원소 추가
		}
		else if (cmd == "remove") {
			cin >> N;
			s &= ~(1 << N); // 원소 제거
		}
		else if (cmd == "check") {
			cin >> N;
			if (s & (1 << N)) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (cmd == "toggle") {
			cin >> N;
			s ^= (1 << N);
		}
		else if (cmd == "all") {
			s = (1 << 21) - 1; // 모두 1로 설정
		}
		else if (cmd == "empty") {
			s = 0;
		}
	}
	return 0;


	/*
	입력 :
	첫째 줄에 수행해야 하는 연산의 수 M (1 ≤ M ≤ 3,000,000)이 주어진다.

	둘째 줄부터 M개의 줄에 수행해야 하는 연산이 한 줄에 하나씩 주어진다.

	add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
	remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
	check x: S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
	toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
	all: S를 {1, 2, ..., 20} 으로 바꾼다.
	empty: S를 공집합으로 바꾼다.

	출력 :
	check 연산이 주어질때 마다 결과를 출력.

	풀이 :
		int[21] 배열을 사용했으나 시간 초과로 실패
		unsigned int의 숫자를 비트마스킹하여 풀이하는 방식으로 해결.
		비트연산자의 사용법 한번 정리해둘 것
	*/
}