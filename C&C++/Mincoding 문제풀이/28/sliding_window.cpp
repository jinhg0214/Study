// https://pro.mincoding.co.kr/problem/SDS_%EC%8A%AC%EB%9D%BC%EC%9D%B4%EB%94%A9%EC%9C%88%EB%8F%84%EC%9A%B0
#include <iostream>

using namespace std;

int n; // 피사체 개수
int w; // 사진기의 폭
int score[100001];

void Input() {
	cin >> n >> w;

	for (int i = 0; i < n; i++) {
		cin >> score[i];
	}
}

// 최대 예술점수가 나오는 곳의 시작, 끝 인덱스 및 최대 예술점수 출력
void slideWindow() {

	int sum_score = 0;

	// 첫 sum_score
	for (int i = 0; i < w; i++) {
		sum_score += score[i];
	}

	// 
	int max_score = -21e8;
	int start_idx = -1;

	for (int i = 0; i <= n - w; i++) {
		if (max_score < sum_score) {
			max_score = sum_score;
			start_idx = i;
		}
		sum_score += score[i+w]; // 뒤는 더하고
		sum_score -= score[i]; // 앞은 뺀다
	}

	cout << start_idx << " " << start_idx + w -1 << " " << max_score << endl;
}

int main() {
	freopen_s(new FILE*, "test.txt", "r", stdin);

	int t, i=1;
	cin >> t;

	while (t--) {
		Input();
	
		cout << "#" << i << " ";
		i++; 

		slideWindow();
	}

	return 0;
}