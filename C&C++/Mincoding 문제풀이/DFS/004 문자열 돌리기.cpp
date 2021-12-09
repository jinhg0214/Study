// 주어진 문자열을 돌려서 원하는 문자열을 만든다
// RSpin은 ABTK -> KABT 로
// LSpin은 ABTK -> BTKA 로
// TurnOver는 ABTK -> KTBA 로 

/*
풀이
- Lv은 4또는 5까지만 -> RSpin을 4번하면 어짜피 자기 자신이 나오기 때문
- 가지는 3가지 (RSpin, LSpin, TurnOver)
- 들어갔다가 나오면서 문자열 다시 원상복구 해줘야함
*/

#include <iostream>
#include <string>

using namespace std;

string start = "ABTK";
string target = "AKTB";

void lspin() {
	char temp = start[0];
	start[0] = start[1];
	start[1] = start[2];
	start[2] = start[3];
	start[3] = temp;
}

void rspin() {
	char temp = start[3];
	for (int t = 3; t > 0; t--) {
		start[t] = start[t - 1];
	}
	start[0] = temp;
}

void tover() {
	char temp[4];
	for (int t = 0; t < 4; t++) {
		temp[3-t] = start[t];
	}
	for (int t = 0; t < 4; t++) {
		start[t] = temp[t];
	}
}

int Min = 9999;
void abc(int level) {

	if (level == 4) return;
	if (start == target) {
		if (Min > level) {
			Min = level;
		}
		return;
	}

	// l
	lspin(); // 왼쪽 돌리기
	abc(level + 1); // 진입
	rspin(); // 원상복구

	// r
	rspin();
	abc(level + 1);
	lspin();

	// t
	tover();
	abc(level + 1);
	tover();
}

int main() {

	abc(0);

	cout << Min;

	return 0;
}

/*
#include <iostream>
#include <string>

using namespace std;

string str = "ABTK";
bool founded = false;
int cnt = 0;

void RSpin() {
	string tmp;
	tmp = str[3] + str.substr(0, 3);
	str = tmp;
}

void LSpin() {
	string tmp;
	tmp = str.substr(1,3) + str[0];
	str = tmp;
}

void TurnOver() {
	string tmp;
	for (int i = 0; i < str.length(); i++) {
		tmp += str[str.length()-1 - i];
	}
	str = tmp;
}

void DFS(int Lv, string target) {
	
	if (Lv >= 4) return; // 방지 조건?? 어떻게 설정할 것인가
	if (founded == true) return;
	if (str == target) {
		cout << Lv << endl;
		founded = true;
		return;
	}

	// R 시도
	RSpin();
	DFS(Lv + 1, target);
	LSpin(); //원상복구

	// L 시도
	LSpin(); 
	DFS(Lv + 1, target);
	RSpin(); //원상복구

	// T 시도
	TurnOver();
	DFS(Lv + 1, target);
	TurnOver();
}

int main() {
	string target ="AKTB";

	DFS(0, target);

	return 0;
}
*/