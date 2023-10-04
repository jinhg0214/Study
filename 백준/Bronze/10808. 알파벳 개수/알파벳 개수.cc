#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;

	int alphabet[26] = { 0 };

	for (char ch : s) {
		alphabet[ch - 'a']++;
	}

	for (auto num : alphabet) {
		cout << num << " ";
	}

	return 0;
}

/*
입력 : 첫째 줄에 단어 S가 주어진다. 
	단어의 길이는 100을 넘지 않으며, 알파벳 소문자로만 이루어져 있다.
출력 : 단어에 포함되어 있는 a의 개수, b의 개수, …, z의 개수를 공백으로 구분해서 출력한다.

풀이 : 
	문자열을 순회하면서 알파벳을 체크 후, alphabet 배열에 나온 알파벳을 +1 해준다
 
*/