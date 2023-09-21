#include <iostream>
#include <string>

using namespace std;

int cnt; // asterisk의 위치를 저장해두는 정수

// 패턴과 파일 이름을 확인하는 함수
bool PatternCheck(string pat, string fileName) {
	int diff = fileName.length() - pat.length();
	if (diff < -1) { // 패턴보다 파일 이름이 짧은 경우는 일치할 수 없음
		// -1인 이유는 a*a, aa와 같은 경우는 허가되기 때문에 3글자와 2글자 비교해야함
		return false;
	}

	// 1. asterisk 이전의 패턴 비교
	for (int i = 0; i < cnt; i++) {
		if (pat[i] != fileName[i]) {
			return false;   
		}
	}

	// 2. asterisk 이후의 패턴 비교. 뒤에서 부터 비교한다.
	for (int i = pat.length() -1; i > cnt; i--) {
		if (pat[i] != fileName[i + diff]) {
			return false;
		}
	}

	return true;
}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);

	int N;
	string pat;
	string fileName;

	// 1. 입력받기
	cin >> N >> pat;

	cnt = pat.find('*'); // 패턴의 몇번째 자리에 asterisk가 있는지 체크해둔다 

	// 2. 각 문자열과 패턴을 비교한다
	for (int i = 0; i < N; i++) {
		cin >> fileName;
		if (PatternCheck(pat, fileName)) {
			cout << "DA" << endl;
		}
		else {
			cout << "NE" << endl;
		}
	}
	
	return 0;
}