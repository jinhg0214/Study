#include <iostream>

using namespace std;

/*
수열 S의 부분 수열의 합으로 나올 수 없는 가장 작은 자연수를 구하는 프로그램

첫째 줄에 수열 S의 크기 N (1 ≤ N ≤ 20)

둘째 줄에는 수열 S (1 <= S <= 100,000)

# 필요 변수

N

수열 S 저장할 arr_s

1~100000까지의 수가 조합이 가능한지를 저장해둘 배열

S의 각 원소는 최대 100,000

즉 최대 100,000가 20번 나올 수 있음

100000 * 20까지 체크해야함

# 알고리즘

1. N 입력받고, 수열 S채우기
2. 재귀함수를 이용해 숫자들을 이용한 합을 만들기
	2-1. 0번 원소부터 sum에 이 수를 더할지 말지 정함
	- 더한다면 다음 재귀함수를 호출할 때 sum에 이 수를 더하고
	- 더하지 않는다면 sum을 그대로 넘겨줌
	2-2. 이를 N개의 원소를 모두 둘러볼 때 까지 확인함
	2-3. N개의 레벨을 모두 둘러봤다면, 현재 저장된 sum값을 조합 가능하다고 check 배열에 표시해둠
3. [1,MAX] 사이의 수 중에서 체크가 되지 않은 수를 찾아 출력 후 종료
*/

#define MAX 20000001

int N;
int arr_s[21];

bool check[MAX];

void recursive(int level, int sum) {
	if (sum > MAX) { return; }
	if (level == N) {
		check[sum] = true;
		return;
	}

	recursive(level + 1, sum + arr_s[level]);
	recursive(level + 1, sum);
}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N; 
	for (int i = 0; i < N; i++) {
		cin >> arr_s[i];
	}

	recursive(0, 0);

	for (int i = 1; i < MAX; i++) {
		if (check[i] == false) {
			cout << i << endl;
			break;
		}
	}

	return 0;
}

