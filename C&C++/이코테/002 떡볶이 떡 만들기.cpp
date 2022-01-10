/*
파라메트릭 서치(Parametric Search)
- 최적화 문제를 결정 문제로 바꾸어 해결하는 기법
- 원하는 조건을 만족하는 가장 알맞은 값을 찾는 문제에 주로 파라메트릭 서치를 사용함.
    ex) 범위 내에서 조건을 만족하는 가장 큰 값을 찾으라는 최적화 문제 -> 이진 탐색으로 결정 문제를 해결하면서 범위를 좁혀나감

---
1. 적절한 높이를 찾을 때 까지 절단기의 높이 H를 반복해서 조정해본다
-> 적절한 높이? 조건을 만족 여부에 따라 

ex) 
    4 6 // 떡은 4줄, 최소 6만큼 줘야한다
    19 15 10 17
    떡의 길이
    ---------- -----|----
    ---------- -----
    ----------
    ---------- -----|--
                    ↑ 칼의 위치를 조절해서 손님에게 줄 떡을 정한다. 15에서 자르면 딱 6만큼 줄 수 있음
    1. 0 - 21e8 의 mid 값 부터 시작해서 자를 위치를 계속 조절해 나감
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> vec; // 떡 길이 저장하는 벡터

void Input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int tmp; cin >> tmp;
		vec.push_back(tmp);
	}
	
	return;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	
	Input();

	// 이진 탐색을 위한 시작점과 끝점 설정
	int start = 0;
	int end = 21e8;

	int res = 0;
	
	// 반복문을 이용한 이진 탐색 이용
	while (start <= end) {
		long long int total = 0; // 손님이 가져가는 떡의 양
		int mid = (start + end) / 2;

		// 현재 길이에서 떡을 잘랐을때 떡의 양 계산하기
		for (int i = 0; i < N; i++) {
			if (vec[i] > mid) { // 현재 칼날이 떡을 자를 수 있음
				total += vec[i] - mid;
			}
		}

		// 손님에게 덜주는 경우, 칼을 왼쪽으로 이동
		if (total < M) {
			end = mid - 1;
		}
		// 손님에게 너무 많이 주는 경우, 칼을 오른쪽으로 이동
		else{
			res = mid; // 그래도 주긴 줬으니 결과를 저장해둔다
			start = mid + 1;
		}

	}

	cout << res;
	return 0;
}