#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> trees;

int my_binary_search(int start, int end, int target) {

	int mid;
	while (start <= end) {
		mid = (start + end) / 2;
		
		// target과 mid로 잘랐을때 얻을수 있는 나무 값을 비교
		long long int sum = 0;
		for(int tree : trees){
			if (tree < mid) continue;
			sum += tree - mid;
		}
		// cout << "얻을수 있는 나무 길이 : " << sum << endl;
		if (sum == target) {
			return mid;
		}
		// 얻을수 있는 나무 길이가 target보다 작다면, H를 높인다 
		else if (sum < target) {
			end = mid - 1;
		}
		// 얻을수 있는 나무 길이가 target보다 크다면, H를 내린다 
		else if(sum > target){
			start = mid + 1;
		}
	}
	return end;
}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> M;
	trees.resize(N);
	
	int max_tree = 0, min_tree = 21e8;
	for (int i = 0; i < N; i++) {
		cin >> trees[i];
		max_tree = max(max_tree, trees[i]);
	}

	cout << my_binary_search(0, max_tree, M);

	return 0;
}
/*

20 15 10 17 나무가 있을때

H를 15로 지정하면

5 0 0 2 만큼 나무를 얻을 수 있다

1. 가장 큰 나무에서 1씩 줄어들면서 구하기 
- worst case : 100만개의 나무 중 하나만 1,000,000,000 이고, 나머지는 1인 경우
- 10억 * 100만으로 1초 안에 불가능

2. 이분 탐색으로 접근
- 가장 작은 나무와 큰 나무를 구하고, 이분탐색으로 접근한다
- 두 나무의 중간값으로 잘랐을때의 결과가 
	- 목표값보다 크다면 H를 더 올린다 
	- 목표값보다 작다면 H를 더 내린다
- 정석적인 이분 탐색일까 upper bound 혹은 lower bound?
- 나무로 자른 값은 중복값이 없을것이므로 정석적인 이분탐색으로 접근해봄

*/