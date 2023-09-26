/*

입력 : N (1<= N <= 100)
	이후 N개의 문자열 주르륵.
	01a2b3456cde478 과 같은 문자열. (최대 100글자. 소문자와 숫자로만 구성됨)

출력 :
	찾은 숫자 M개를 M개의 줄에 걸쳐 출력.
	오름차순으로 정렬하여 출력하기

풀이 :
	문자열 문제인 만큼 숫자를 int형으로 처리 불가
	(2^16은 약 2147,000,000 인데 100글자 입력이 있음 ex) 999....99a9)
	long long int로도 처리 불가능하므로, string으로 처리해야함

	세줄요약 :
	1. 일단 숫자 뽑아서
	2. 배열에 저장한뒤
	3. 배열을 정렬한다

	상세
	1. N을 입력받는다
	2. 문자열을 N번 입력받으면서 배열에 숫자만 저장한다(3~5)
	3. input에 입력 받은 뒤, input 문자열의 각 char를 확인한다
	4. 숫자라면 tmp에 그 문자를 저장한다
	5. 숫자가 아니라면 tmp에 저장된 문자열을 확인한다.
		- 문자열이 비어있으면? 패스
		- 문자열이 0으로 시작하면? 앞의 0을 지워준다.
			(한글자 이상이고, 0으로 시작하면)
	6. 문자열 입력이 끝났으면 배열에 저장된 문자열들을 정렬한다
	7. 출력
*/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // for sort

using namespace std;


// 문자열 길이 비교 함수
bool cmp(string a, string b) {
	if (a.size() == b.size()) {
		return a < b;
	}
	return a.size() < b.size();
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
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

				// tmp가 0으로 시작하면 앞의 0을 직접 지워줌
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