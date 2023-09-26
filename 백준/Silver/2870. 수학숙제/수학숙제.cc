#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // for sort

using namespace std;

bool cmp(string a, string b) {
	if (a.size() == b.size()) {
		return a < b;
	}
	return a.size() < b.size();
}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	int N;
	string input;
	vector<string> result;

	cin >> N;
	while (N--) {
		cin >> input;
		string tmp = "";

		for (int i = 0; i <= input.length(); i++) {
			// 숫자라면
			if ('0' <= input[i] && input[i] <= '9') {
				tmp += input[i];
 			}
			else {
				if (tmp == "") continue; // 아무것도 내용없으면 패스
				
				// tmp가 0으로 시작하면 앞의 0을 지워줌
				while (tmp.size() > 1 && tmp[0] == '0') {
					tmp.erase(0, 1);
				}

				result.push_back(tmp);
				tmp.clear();
			}
		}
	}

	sort(result.begin(), result.end(), cmp);

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
		
	return 0;
}