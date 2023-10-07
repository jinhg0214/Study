#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string word;
int base[26] = { 0 };

bool Check(string str) {
	// 각 문자의 알파벳 개수 확인
	int table[26];

	copy(base, base + 26, table);

	// 첫번째 단어의 알파벳과 비교한다. (기존의 테이블과 비교하면서 빼준다.
	for(char ch:str){
		table[ch - 'A']--;
	}

	int diff = 0;
	for (int i = 0; i < 26; i++) {
		if (table[i] != 0) {
			diff++;
		}
	}
	 
	// 같은 구성을 갖는 경우 ,알파벳의 등장회수가 같음
	// 한 문자를 더하거나 빼면 같은 구성을 가지는 경우,
	// 한 알파벳만 등장 회수가 1 차이남
	if (diff == 0 || diff == 1) {
		return true;
	}
	// 한 문자를 다른 문자로 바꾸면 같은 구성을 갖는 경우,
	// 두 알파벳 등장의 회수가 각각 -1, 1씩 차이남
	else if (diff == 2) {
		bool flag = false;
		for (int i = 0; i < 26; i++) {
			if (table[i] == 1) {
				for (int j = 0; j < 26; j++) {
					if (table[j] == -1) {
						flag = true;
					}
				}
			}
		}
		if (flag == true) {
			return true;
		}
	}
	return false;

}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	int n;
	int result = 0;
	
	cin >> n >> word;

	// 첫번째 단어의 알파벳 확인
	for (char ch : word) {
		base[ch - 'A']++;
	}

	// 각 문자와 비슷한 단어인지 체크
	for (int i = 0; i < n - 1; i++) {
		string new_word;
		cin >> new_word;

		if (Check(new_word) == true) {
			result++;
		}
	}
	cout << result;

	return 0;
}