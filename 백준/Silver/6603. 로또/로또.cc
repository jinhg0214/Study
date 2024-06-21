#include <bits/stdc++.h>

using namespace std;

int main(){
	// freopen_s(new FILE*, "input.txt", "r", stdin);

	while (1) {
		int k;	cin >> k;
		if (k == 0) break;
		vector<int> v(k);
		for (int i = 0; i < k; i++)
			cin >> v[i];

		vector<int> idx; // 조합을 위한 index 벡터. next_permutation으로 조합 생성용
		for (int i = 0; i < 6; i++) // 0일떄 뽑는다
			idx.push_back(0);

		for (int i = 0; i < k - 6; i++) // 1일때 거른다
			idx.push_back(1);

		// 조합 생성
		do {
			for (int i = 0; i<v.size(); i++) {
				if (idx[i] == 0) { 
					cout << v[i] << ' ';
				}
			} cout << '\n';

		} while (next_permutation(idx.begin(),idx.end()));
		cout << '\n';
	}
	
	return 0;
}
