#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// freopen_s(new FILE*, "sample_input.txt", "r", stdin);
	int T, n;

	cin >> T;

	while (T--) {
		vector<int> res;
		cin >> n;
        
        // >> shift를 이용한 2진수 변환
		for (int i = 21; i >= 0; i--)
		{
			int temp = (n >> i) & 1;
			/*cout << temp;*/
            // 값이 1인 비트만 벡터에 저장해둠
			if (temp == 1) {
				res.push_back(i);
			}
		}
        // 뒤집어서 출력
		reverse(res.begin(), res.end());

		for (std::vector<int>::iterator iter = res.begin(); iter != res.end(); iter++) {
			cout << *iter << " ";
		}
		cout << '\n';
	}
    
	return 0;
}