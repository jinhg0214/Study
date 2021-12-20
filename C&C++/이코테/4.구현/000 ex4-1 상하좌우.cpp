/*L, R, U, D 하나의 문자를 받아 이동하는 프로그램
*/

#include <iostream>
#include <string>

using namespace std;

int N;
string plans;
int y = 1, x = 1;

int direct[4][2] = {0, -1, 0, 1, -1, 0, 1, 0};// L R U D
char moveTypes[4] = { 'L', 'R', 'U', 'D' };

int main() {
	cin >> N;
	cin.ignore(); // cin과 getline을 같이 사용하기 위해선 버퍼를 비워줘야한다
	getline(cin, plans); // string lib에 정의되어있음. 명령을 아예 줄로 받는다

	// 문자열의 문자를 하나씩 확인. 띄어쓰기도 본다
	for (int i = 0; i < plans.size(); i++) {
		char plan = plans[i];

		int dx = -1, dy = -1;

		for (int j = 0; j < 4; j++) {
			if (plan == moveTypes[j]) { // 명령 4개중(L R U D)에 있는지 확인 if (plan == 'U)랑 같은 처리임
				dy = y + direct[j][0];
				dx = x + direct[j][1];
			}
		}
		if (dy < 1 || dx < 1 || dy > N || dx > N) continue; // 경계처리
		x = dx;
		y = dy;
	}

	cout << x << ' ' << y << endl;

	return 0;
}