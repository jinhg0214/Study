#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n, k;
vector<int> v;
int used[11];

vector<string> result;

void DFS(int level, string num) {
	if (level == k) {
		result.push_back(num);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (used[i] == 1) continue; // 이미 사용한 카드

		used[i] = 1;
		string tmp = num;
		tmp += to_string(v[i]);
		DFS(level + 1, tmp);
		// 한자리수 숫자가 아닐수도 있음 두자리면 두개 pop 해야함
		used[i] = 0;
	}

	return;
}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> n >> k;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	DFS(0, "");

	// unique 함수와 erase 함수를 이용해 중복 원소 제거
	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()), result.end()); 

	cout << result.size();

	return 0;
}