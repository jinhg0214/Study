/*
백준 1032 https://www.acmicpc.net/problem/1032

문제 분석
검색 결과를 보고 무엇을 입력했는지 유추하는 문제
1. 파일 이름 개수 : N개 ( 1<= N <= 50)
2. N개 줄에 파일 이름을 나열 : str[n] (str[n]은 최대 50글자)
3. 파일 이름은 알파벳 소문자와 '.', '?'으로만 이루어 져있다. !! '*'는 이번 문제에 없음 !!

문제 풀이
0. 입력 받고 
1. string ans에 첫번째 문자열(str[0])을 복사한뒤,
2. str[n]에 저장된 모든 문자열들과 비교한다.
	2-1. 각 글자를 비교 후, 다른 글자가 있으면 ans에 그 글자 위치를 '?'로 기록해둔다

*/

#include <iostream>
#include <string>

using namespace std;

int main() {
	// freopen_s(new FILE*, "sample_input.txt", "r", stdin);

	int N;
	string str[51];
	string ans;

	// 0. 입력받기
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}

	// 1. ans에 str[0]을 복사
	ans = str[0];

	// 2. str[1] ~ str[N-1]까지 비교한다
	int strlen = ans.length();
	for (int i = 1; i < N; i++) {
		// 문자열 끝까지 다른 글자가 있는지 체크
		for (int j = 0; j < strlen; j++) {
			if (ans[j] != str[i][j]) {
				ans[j] = '?'; // 다른 글자가 있다면 ? 를 기록해둔다
			}
		}
	}

	cout << ans << '\n';

	return 0;
}