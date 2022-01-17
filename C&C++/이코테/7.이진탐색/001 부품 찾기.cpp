#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int binary_search(vector<int> vect, int target, int start, int end) {
	if (start > end) {
		return -1;
	}
	int mid = (start + end) / 2;

	// 일치하는 경우
	if (vect[mid] == target) {
		return mid;
	}
	// 중간값보다 target이 큰경우, 오른쪽을 살펴본다
	else if(vect[mid] < target) {
		return binary_search(vect, target, mid + 1, end);
	}
	// 중간값보다 target이 작은 경우, 왼쪽을 살펴본다
	else {
		return binary_search(vect, target, start, mid -1);
	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	int N, M, temp;
	vector<int> li;
	vector<int> req;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		li.push_back(temp);
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> temp;
		req.push_back(temp);
	}
	
	sort(li.begin(), li.end());
	sort(req.begin(), req.end());

	// 요청한 원소 각각이 리스트에 있는지 확인한다
	for (int i = 0; i < M; i++) {
		int start = 0, end = li.size() - 1, res;
		res = binary_search(li, req[i], start, end);
		if (res == -1) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES : " << res + 1 << endl; // 위치를 출력함
		}
	}

	return 0;
}