#include <iostream>
#include <string>

using namespace std;

int main() {
	string input[5];
	int cnt = 0;

	for (int i = 0; i < 5; i++) {
		cin >> input[i];

		// 첫번째 찾은 위치
		int pos = input[i].find("MCD");

		// 이후에도 있는지 확인
		while(pos != std::string::npos){
			cnt++;
			pos = input[i].find("MCD",pos+1);
		}

	}

	cout << cnt;

	return 0;
}