/*
입력 : 영어 단어의 개수 N, 외울 단어의 길이 기준 M (1<= N <= 100000, 1<=M<=10)
	둘째 줄 부터 N+1번째 줄까지 외울 단어 입력
	단어는 알파벳 소문자로만 입력됨. 단어의 길이는 10 을 넘지 않음.

출력 : 단어를 단어장 앞에 위치한 단어부터 한줄에 한 단어씩 출력
	정렬 순서
	1. 자주 나오는 단어일수록 앞에 배치한다.
	2. 해당 단어의 길이가 길수록 앞에 배치한다.
	3. 알파벳 사전 순으로 앞에 있는 단어일수록 앞에 배치한다
	
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool comp(pair<string, int>& a, pair<string, int>& b) {
	// 1. 자주 나오는 단어일수록 앞에 배치
	if (a.second == b.second) {
		// 2. 해당 단어의 길이가 길수록 앞에 배치
		if (a.first.length() == b.first.length()) {
			// 3. 3. 알파벳 사전 순으로 앞에 있는 단어일수록 앞에 배치한다
			return a.first < b.first;
		}
		return a.first.length() > b.first.length();
	}
	return a.second > b.second;
}

int main() {
	// C와 C++의 표준 stream 의 동기화를 끊는 역할을 하여, cin/cout의 입출력 속도를 높히는기능
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 

	// freopen_s(new FILE*, "input.txt", "r", stdin);

	int N, M;
	cin >> N >> M;

	unordered_map<string, int> note;

	while (N--) {
		string input;
		cin >> input;

		// 단어 길이가 M보다 짧으면 단어장에 넣지 않음
		if (input.length() < M) continue;
		
		unordered_map<string, int>::iterator FindIter = note.find(input);

		if (FindIter != note.end()) {
			FindIter->second++; 
		}
		else {
			note.insert(make_pair(input, 1));
		}
		

	}

	// 정렬
	vector<pair<string, int>> v(note.begin(), note.end()); // 2차원 벡터를 만들어 맵의 정보를 복사해 저장
	sort(v.begin(), v.end(), comp); // 생성한 정렬 기준함수를 이용해 정렬
	for (auto i : v) cout << i.first << "\n";

	return 0;
}