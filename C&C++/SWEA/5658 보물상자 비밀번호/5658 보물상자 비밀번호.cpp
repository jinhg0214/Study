// SWEA 5658

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int T, i=1;
int N, K;
int slide_start, window_size;
int ans;
vector<int> res;

string str;

void Input() {
	// init
	res.clear();
	ans = 0;

	// input
	cin >> N >> K;
	cin >> str;

	// 
	slide_start = 0;
	window_size = N / 4;
	str = str.append(str);
}

int Tmp_to_int(string str) {
	int ret = 0;
	int tmp;

	for (int i = 0; i < str.length(); i++) {
		if ('A' <= str[i] && str[i] <= 'F') {
			tmp = pow(16, str.length() - 1 - i) * (str[i] - 'A' + 10);
			ret += tmp;
		}
		else {
			tmp = pow(16, str.length() - 1 - i) * (str[i] - '0');
			ret += tmp;
		}
	}

	return ret;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> T;
	while (T--) {
		Input();

		while (1) {
			// 종료 조건
			if (slide_start == N) break; 

			string tmp = str.substr(slide_start, window_size);
			// tmp to hex
			int val = Tmp_to_int(tmp);
			res.push_back(val);

			// 한칸 옆으로 이동
			slide_start++;
			// slide_right++;
		}
		// sort
		sort(res.begin(), res.end(), greater<int>());

		// K번째로 큰 수 출력하기
		int cnt = 1;
		int same_num_cnt = 0;
		while (cnt < K) {
			if (res[cnt] == res[cnt - 1]) { // 두 수의 크기가 같다면 같은수 체크
				same_num_cnt++;
			}
			cnt++;
		}
		ans = res[cnt - 1 + same_num_cnt];

		cout << "#" << i++ << " " << ans << endl;
	}


	return 0;
}