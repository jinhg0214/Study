#include <iostream>

using namespace std;

int total_2, total_5;

void func(int n) {
	if (n == 0 || n == 1) { return; }

	int tmp = n;
	while (1) {
		if (tmp % 2 == 0) {
			total_2++;
			tmp /= 2;
		}
		else if (tmp % 5 == 0) {
			total_5++;
			tmp /= 5;
		}
		else {
			break;
		}
	}

	func(n - 1);
}

int main() {
	int N;
	cin >> N;

	func(N);
	
	cout << min(total_2, total_5);

	return 0;
}

/*
1. factorial을 이용해 직접 수를 구하고, 0을 세는 방법
-> 불가능! 500!를 직접 구하는건 unsigned long long int 로도 불가능

2. 소인수 분해를 통해 2*5의 개수를 찾기

 500!를 소인수 분해 해서, 2와 5의 개수를 찾고, 그 중 작은 개수만큼 0이 존재함
 예를들어 5!라면, 1,2,3,4,5 -> 2 : 3개, 5 : 1개이므로, 0은 한개 존재. 120이므로 1개 존재
*/