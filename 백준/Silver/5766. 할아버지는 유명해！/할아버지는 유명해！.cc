#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

#define MAX 10001

int player[MAX] = { 0 };

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	int N, M;

	while (1) {
		scanf("%d %d", &N, &M);
		if (N == 0 && M == 0) break;
		memset(player, 0, sizeof(player));
	
		for (int i = 0; i < N; i++) {
			// 1. N주차 스코어 정보 입력받기
			for (int j = 0; j < M; j++) {
				int tmp = 0;
				scanf("%d", &tmp);
				player[tmp] += 1;
			}

		}	
		// 2. 그 주차의 2등 선수 출력
			// 2-1. 먼저 1등 선수를 찾는다
		int mvp_score = 0, mvp_idx;
		for (int i = 0; i < MAX; i++) {
			if (mvp_score < player[i]) {
				mvp_idx = i;
				mvp_score = player[i];
			}
		}

		// 리더보드의 복사본
		int player_backup[MAX];
		memcpy(player_backup, player, sizeof(player));

		// 2등을 찾기 위해 1등 삭제
		player_backup[mvp_idx] = 0;

		// 일단 2등 점수를 찾고
		int second_score = 0;
		for (int i = 0; i < MAX; i++) {
			if (second_score < player_backup[i]) {
				second_score = player_backup[i];
			}
		}
		// 이 점수와 같은 점수를 갖는 선수들을 찾는다
		vector<int> res;
		for (int i = 0; i < MAX; i++) {
			if (second_score == player_backup[i]) {
				res.push_back(i);
			}
		}

		for (int e : res) {
			cout << e << " ";
		}
		cout << endl;
	}

	return 0;
}

/*
각 선수는 1~10000까지의 정수(선수 번호)로 식별

테스트 케이스의 첫 행에는 두 정수 N과 M

다음 행부터 N(2<=N<=500)주 동안의 매주 상위 M(2<=M<=500)명의 랭킹 정보가 주어짐

그 다음 N행의 인풋이 주어지는데 각 행은 한 주의 랭킹 정보

각 행은 공백으로 구분되는 M개의 정수들이 주어짐

ex)

4 5
20 33 25 32 99
32 86 99 25 10
20 99 10 33 86
19 33 74 99 32

4주 정보, 5명의 선수

3 6
2 34 67 36 79 93
100 38 21 76 91 85
32 23 85 31 88 1

3주차 정보, 6명의 선수

각 테스트 케이스에는 최고점의 선수가 단 한 명만 존재 <- 동점 없음
매주마다의 랭킹 정보에는 서로 다른 M개의 선수 번호가 주어짐 <- ?

N과 M이 모두 0으로 주어지는 행이 인풋의 마지막임

각 테스트 케이스마다,  당신의 프로그램은 한 행에 2등인 선수(들)의 번호를 출력

테스트 케이스가 바뀔때마다 리더보드가 초기화된다

2등인 선수가 두 명 이상인 경우(동점자 발생), 각 선수 번호를 공백으로 구분하여 오름차순으로 출력

필요 변수

10000 명의 선수의 스코어를 저장할 player 배열

랭킹 정보의 개수 N, 선수 스코어 정보 개수 M

// 1. N주차 스코어 정보 입력받기에서
매주 랭킹에 선수의 이름이 오를 때마다 선수의 포인트가 1포인트씩 오른다고함
주어지는 숫자는 순위가 아니라 다같이 1점씩 받는거임

문제를 잘 읽자!!

*/