/*
입력: 
트럭을 한 대 주차할 때는 1분에 한 대당 A원을 내야 한다. 
두 대를 주차할 때는 1분에 한 대당 B원, 
세 대를 주차할 때는 1분에 한 대당 C원을 내야 한다.

첫째 줄에 문제에서 설명한 주차 요금 A, B, C가 주어진다. (1 ≤ C ≤ B ≤ A ≤ 100)
다음 세 개 줄에는 두 정수가 주어짐. 상근이가 가지고 있는 트럭이 주차장에 도착한 시간과 주차장에서 떠난 시간

출력 :
상근이가 내야하는 주차 요금 출력.

풀이 :
	현 시간에 동시에 몇대가 주차되어있는지 체크해야함.
	시간 배열을 만들어놓고 그 시간대에 주차장에 상근이 차가 몇대 주차되어있는지 체크

	time[101]

*/

#include <iostream>

using namespace std;

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);

	int A, B, C;
	int start, end;
	int time[101] = { 0 };
	
	int price = 0;

	cin >> A >> B >> C;
	
	for (int i = 0; i < 3; i++) {
		cin >> start >> end;

		for (int j = start; j < end; j++) {
			time[j]++; 
		}
	}
	
	for (int i = 0; i < 101; i++) {
		if (time[i] == 0) {
			continue;
		}
		else if (time[i] == 1) {
			price += A;
		}
		else if (time[i] == 2) {
			price += B * 2;
		}
		else{
			price += C * 3;
		}
	}

	cout << price;
  
	return 0;
}