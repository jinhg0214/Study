#include <iostream>
#include <string>

using namespace std;

int table[26] = { 0 };

// 펠린드롬이 가능한지 확인하는 함수
bool IsPalindromePossible(string str) {
	// 알파벳 개수 체크
	for (char ch : str) {
		table[ch - 'A']++; // str은 알파벳 대문자로만 된 최대 50글자
	}

	// 알파벳이 홀수개인 문자는 하나만 존재해야함
	bool oddFlag = false;
	for (int i = 0; i < 26; i++) {
		if (table[i] == 0) continue;
		// 홀수인 알파벳이 이미 있는데 또 홀수인 알파벳이 존재한다면 펠린드롬 불가
		if (oddFlag == true && table[i] % 2 != 0) { return false; }
		if (table[i] % 2 != 0) { oddFlag = true; }
	}
	return true;
}

// 문자열을 받아 펠린드롬을 만들어 반환하는 함수
string MakePalindrome(string str) {
	string result = "";

	// 문자열 길이가 홀수인 경우에는 
	// 홀수개인 알파벳을 먼저 찾아서 하나만 가운데 배치
	if (str.size() % 2 == 1) {
		for (int i = 0; i < 26; i++) {
			if (table[i] % 2 == 1) {
				char ch = 'A' + i;
				result.push_back(ch);
				table[i]--;
				break;
			}
		}
	}

	// Z부터 순서로 문자열 앞과 뒤에 붙인다 "ZZ", "YZZY", ...,"AB...XYZZYX...BA"
	// 정답이 여러 개일 경우에는 사전순으로 앞서는 것을 출력하기 때문
	for (int i = 25; i >= 0; i--) {
		if (table[i] == 0) continue;
		while (table[i] != 0) {
			char ch = 'A' + i;
			result.insert(0, 1, ch);
			result.push_back(ch);
			table[i] = table[i] - 2;
		}
	}
	return result;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	string str;
	cin >> str;

	if (IsPalindromePossible(str)) {
		cout << MakePalindrome(str);
	}
	else {
		cout << "I'm Sorry Hansoo";
	}

	return 0;
}

/*
입력 : 알파벳 대문자로만 된 최대 50글자
출력 : 문자열을 받아서 펠린드롬을 만들수 있는지 확인하고, 이를 펠린드롬으로 만들어 출력.
	불가능 한 경우 "I'm Sorry Hansoo"를 출력,
	가능한 경우, 사전순으로 앞서는 것을 출력

풀이 :
크게 펠린드롬 체크 파트와, 펠린드롬 제작 파트로 나눔
1. 펠린드롬 체크
	- 문자열을 받아 알파벳 개수를 체크함
    - 이후, 알파벳 개수가 홀수인 알파벳이 두개 이상이라면 펠린드롬을 만들 수 없으므로 false 리턴
    하나 혹은 0개라면 true 리턴

2. 펠린드롬 체크를 통과했다면, 이 문자열을 이용해 펠린드롬을 만듬
	2.1 짝수라면, A-Z 26을 Z부터 안에서부터 배치해나감
	// Z부터 순서로 문자열 앞과 뒤에 붙인다 "ZZ", "YZZY", ...,"AB...XYZZYX...BA"
	// 정답이 여러 개일 경우에는 사전순으로 앞서는 것을 출력하기 때문
	2.2 홀수라면, 가운데 홀수인 알파벳에서 하나 빼와서 배치하고, 짝수와 같은 순서로 진행함
   
    -> 두 과정의 차이는 홀수 체크인 부분밖에 없으므로, 홀수인 알파벳 하나 가운데 배치하고 짝수 배치하는식으로도 개선 가능할듯

*/