#include <iostream>
#include <algorithm>

using namespace std;

struct Person {
	int contry;
	int num;
	int score;
};

bool compare(Person& a, Person& b) {
	// 1. 점수 순으로 비교. 동점자는 없음
	return a.score > b.score; 
}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	
	int n;
	Person person[101];

	// 1. input
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> person[i].contry >> person[i].num >> person[i].score;
	}

	// 2. 정렬
	sort(person, person + n, compare);

	// 3. 메달 수여
	cout << person[0].contry << " " << person[0].num << '\n';
	cout << person[1].contry << " " << person[1].num << '\n';
	// 1.2등은 국가가 같더라도 문제가 되지 않으므로 그대로 출력


	// 3등 부터는 국가가 같은지 체크 후 출력한다
	int d = 2;
	while (1) {
		if (person[0].contry == person[d].contry) {
			d++;
		}
		else {
			cout << person[d].contry << " " << person[d].num << '\n';
			break;
		}
	}


	return 0;
}

/*
입력 : 
	첫 번째 줄에는 대회참가 학생 수를 나타내는 N이 주어진다. 단, 3 ≤ N ≤ 100이다.
	두 번째 줄부터 N개의 줄에는 각 줄마다 한 학생의 소속 국가 번호, 학생 번호, 
	그리고 성적이 하나의 빈칸을 사이에 두고 주어진다.
	단, 국가 번호는 1부터 순서대로 하나의 정수로 주어지며, 
	각 학생번호는 각 나라별로 1부터 순서대로 하나의 정수로 주어진다, 
	점수는 0 이상 1000 이하의 정수이고, 동점자는 없다고 가정한다.
	입력으로 제공되는 국가는 적어도 두 나라 이상이다.

출력 :
	메달을 받는 학생들을 금, 은, 동메달 순서대로 한 줄에 한 명씩 출력한다. 
	즉, 첫 번째 줄에는 금메달 수상자를, 두 번째 줄에는 은메달 수상자를, 
	세 번째 줄에는 동메달 수상자를 출력한다. 
	하나의 줄에는 소속국가 번호와 학생 번호를 하나의 빈칸을 사이에 두고 출력한다.

풀이 :
	구조체 정렬 문제 + 구현 문제
	먼저 algorithm sort를 이용해 구조체를 점수순으로 정렬한 뒤에, 
	메달 3개를 국가가 겹치지 않게 분배한다

	1. 입력받기
	2. 정렬
	3. 메달을 수여
		- 1,2등은 겹쳐도 상관없으나 3등부터는 확인 필요

*/