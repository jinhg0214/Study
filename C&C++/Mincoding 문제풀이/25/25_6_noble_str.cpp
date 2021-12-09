#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 문자열 안의 <>가 고결한지 확인하는 함수 
bool isNoble(string str) {

	int a = 0;
	int b = 0;
	

	while (1) {
		// < > 안의 문자열을
		a = str.find('<',a);
		b = str.find('>',b);

		if (b == -1)break;

		string tmp = str.substr(a + 1, b - a - 1);

		// 중복 알파벳이 존재하는지 확인
		for (int i = 0; i < tmp.size(); i++) {
			int cnt = 0;
			for (int j = 0; j < tmp.size(); j++) {
				if (tmp[i] == tmp[j]) {
					cnt++;
				}
				if (cnt == 2) { return false; }
			}

			
		}

		// 중복알파벳이 존재하지 않으면 갱신
		a = b + 1;
		b = a + 1;
	}
	
	return true;
}

int main() {
	// freopen_s(new FILE*, "test.txt", "r", stdin);

	int n;

	cin >> n;

	vector<string> input(n);

	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	
	for (int i = 0; i < n; i++) {
		if (isNoble(input[i]) == true) {
			cout << "O";
		}
		else {
			cout << "X";
		}
	}

	


	return 0;
}