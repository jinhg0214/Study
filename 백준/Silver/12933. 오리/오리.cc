#include <iostream>
#include <string>

using namespace std;

string duck[501];

int main() {
	string record;
	cin >> record;
	//record = "qquackuack";

	int max_duck_size = 1;

	for (char ch : record) {
		bool isPushed = false;

		///
		if (ch == 'q') {
			for (int i = 1; i <= max_duck_size; i++) {
				if (isPushed) break;
				if (duck[i].size() % 5 == 0) {
					duck[i].push_back(ch);
					isPushed = true;
				}
			}
			// 새로운 q가 나타났는데, 들어갈 자리가 없다면 오리 한마리 추가
			if (isPushed == false) {
				max_duck_size++;
				duck[max_duck_size].push_back(ch);
				isPushed = true;
			}
			
		}
		else if (ch == 'u') {
			for (int i = 1; i <= max_duck_size; i++) {
				if (isPushed) break;
				if (duck[i].size() % 5 == 1) {
					duck[i].push_back(ch);
					isPushed = true;
				}
			}
		}
		else if (ch == 'a') {
			for (int i = 1; i <= max_duck_size; i++) {
				if (isPushed) break;
				if (duck[i].size() % 5 == 2) {
					duck[i].push_back(ch);
					isPushed = true;
				}
			}
		}
		else if (ch == 'c') {
			for (int i = 1; i <= max_duck_size; i++) {
				if (isPushed) break;
				if (duck[i].size() % 5 == 3) {
					duck[i].push_back(ch);
					isPushed = true;
				}
			}
		}
		else if (ch == 'k') {
			for (int i = 1; i <= max_duck_size; i++) {
				if (isPushed) break;
				if (duck[i].size() % 5 == 4) {
					duck[i].push_back(ch);
					isPushed = true;
				}
			}
		}

		if (isPushed == false) {
			cout << -1;
			return 0;
		}
	}

	// 녹음을 다 돌렸으나 음성이 완성되지 않은 경우를 체크 ex) quackqua
	for (int i = 1; i <= max_duck_size; i++) {
		if (duck[i].size() % 5 != 0) {
			cout << -1;
			return 0;
		}
	}

	cout << max_duck_size;
	return 0;
}
