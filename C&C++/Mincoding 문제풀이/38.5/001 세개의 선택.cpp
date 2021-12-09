/*
3*3 숫자판에서 3개의 숫자를 선택
가장 큰 값을 가지는 경우의 총 수를 구하는 문제

풀이 : 
3개의 숫자를 선택 -> 중복을 허용하지 않는 조합 문제
근데 2차원 배열의 조합은 어떻게? => 1차원 배열로 생각하고 처리
(0,0) (0,1) (0,2)
(1,0) (1,1) (1,2) => 00 01 02 10 11 12 20 21 22 로 펴서 생각한다
(2,0) (2,1) (2,2)

1. DFS를 돌려 3개 선택 조합 후 곱을 hash에 (곱, 개수)로 저장한다
2. key : prod가 가장 큰 값을 선택 후, 그 value인 개수를 출력한다.
*/
#include <iostream>
#include <unordered_map>

using namespace std;

int map[3][3];
int used[3][3];
unordered_map<int, int> um;

void dfs(int start, int Lv, int prod) {

	if (Lv == 3) {
		if (um.count(prod) != 0) {
			um[prod]++;
		}
		else {
			um[prod] = 1;
		}

		return;
	}

	// 2차원 배열을 1차원적으로 접근한다
	int yy;
	int xx;
	for (int i = start; i < 3 * 3; i++) {
		yy = i / 3;
		xx = i % 3;

		if (used[yy][xx] == 1) continue;
		used[yy][xx] = 1;
		dfs(i, Lv + 1, prod * map[yy][xx]);
		used[yy][xx] = 0;
	}
}

void Input() {
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			cin >> map[y][x];
		}
	}
}

int main() {
	freopen_s(new FILE*, "test.txt", "r", stdin);
	Input();

	// 1. DFS돌려서 값들을 저장한다
	dfs(0, 0, 1);

	// 2. um에서 key 값이 가장 큰 값을 찾는다.
	int Max = 0;
	int cnt = 0;
	for (auto i = um.begin(); i != um.end(); i++) {
		if (i->first > Max) {
			Max = i->first;
			cnt = i->second;
		}
	}

	cout << cnt;

	return 0;
}