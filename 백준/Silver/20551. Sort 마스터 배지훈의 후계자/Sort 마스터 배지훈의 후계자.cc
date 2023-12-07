#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	int N, M;
	scanf("%d %d", &N, & M);

	vector<int> a(N);
	for (int i = 0; i < N; i++) {
		int tmp; scanf("%d", &tmp);
		a[i] = tmp;
	}

	sort(a.begin(), a.end());

	for (int i = 0; i < M; i++) {
		int D; scanf("%d", &D);
	
		int res = lower_bound(a.begin(), a.end(), D) - a.begin();

		if (res != N && a[res] == D) {
			// lower_bound는 근사치를 찾기 때문에 일치하는 값이 없더라도 근처까지 감
			// 값이 일치하는지 확인하는 과정 필요
			printf("%d\n", res);
		}
		else {
			printf("-1\n");
		}
	}

	return 0;
}


/*
문제 분석
---
배열 A의 원소의 개수를 저장할 int N (1 <= N <= 2 * 100,000) 

질문의 개수를 저장할 int M (1 <= N <= 2 * 100,000) 

배열 A의 원소를 저장할 벡터<int> A (-1,000,000,000 <= A_i <= 1,000,000,000)

A를 정렬한 벡터<int> B

현재 질문 원소 D (-1,000,000,000 <= D <= 1,000,000,000)


# 알고리즘
```
1. N과 M을 입력받는다
2. N번 반복하여 A의 원소들 입력받는다 O(N)
3. A를 정렬하여 B를 만든다 (?) // algorithm sort 사용함
4. M번 검색을 반복한다
	4-1. 정수 D를 입력받아 이 원소가 배열 B에 있는지 확인한다 <- 이부분의 시간복잡도에 주의
	4-2.  
```

이분탐색으로 해결하려 했으나, 중복 원소가 존재할 때 처음 등장한 위치를 찾지 못하는 문제 발생

2중 for문으로 시간내에 가능할줄 알고 시도했으나 시간초과 발생
	// 2중 for문의 시간 복잡도 계산
	// M은 최대 2×10^5
	// 배열 B의 최대 크기는 2×10^5
	// worst case는 2 * 10^5 * 2 * 10^5 = 4 * 10^10 = 40,000,000,000 으로 약 400억
	// 10억에 1초라고 치면 40초로 시간 초과 발생

	for (int i = 0; i < M; i++) {
		int D;  cin >> D;
		bool flag = false;
		for(int j=0; j<a.size(); j++){
			if(a[j] == D){
				flag = true;
				cout << j << endl;
				break;
			}
		}
		if(flag) cout << -1 << endl;
	}



결국 이분탐색을 수행해야하는데, 처음 나오는 원소의 자리를 이분 탐색으로 어떻게 찾는지가 관건

[중복 여부에 따른 이진탐색](https://yu5501.tistory.com/80)

https://hee96-story.tistory.com/80
->  lower bound와 upper bound 는 이진탐색 알고리즘에서 약간 변형된 것으로 중복된 자료가 있을때 유용하게 탐색할 수 있는 알고리즘



*/