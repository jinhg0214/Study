// 간단한 수학문제였음

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	int T;
	cin >> T;
	while (T--) {
		int ans = 0;
		int cnt, b_cnt = 0, w_cnt = 0;
		string str, tar;
		cin >> cnt >> str >> tar;

		// 현재 오셀로 말들을 보고 흰색, 검은색이 몇개있는지 확인한다
		for (int i = 0; i < str.length(); i++) {


			if (str[i] == 'B' && tar[i] == 'W') {
				b_cnt++; 
			}
			else if (str[i] == 'W' && tar[i] == 'B') {
				w_cnt++;
			}
		}
		// 검은돌, 흰색돌중에 작은 수 만큼 교환후, 나머지는 그냥 뒤집기
		ans += min(b_cnt, w_cnt);
		ans += abs(b_cnt - w_cnt);

		cout << ans << endl;
	}


	return 0;
}