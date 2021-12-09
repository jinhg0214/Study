#include <iostream>
#include <string>

using namespace std;

bool isValid(string str) {

	// 0. 숫자는 안됨
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			return false;
		}
	}

	// 1. bad, no, puck이 존재하면 false
	if (str.find("bad") != -1 || str.find("no") != -1 || str.find("puck") != -1) {
		return false;
	}

	// 2 . 연속적인 언더바 "_"가 5개면 탈락
	if (str.find("_____") != -1) {
		return false;
	}


	// 3. 각 알파벳 사용횟수가 5회 이하(대소문자 별개)
	int upper_cnt[26] = { 0 };
	int lower_cnt[26] = { 0 };

	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			upper_cnt[str[i] - 'A']++;
			
			if (upper_cnt[str[i] - 'A'] > 5) {
				return false;
			}
		} 
		else if (str[i] >= 'a' && str[i] <= 'z') {
			lower_cnt[str[i] - 'a']++;

			if (lower_cnt[str[i] - 'a'] > 5) {
				return false;
			}
		}
		
		
	}
	
	return true;
}

int main() {
	string str;

	cin >> str;

	if (isValid(str) == true) {
		cout << "pass";
	}
	else {
		cout << "fail";
	}

	return 0;
}