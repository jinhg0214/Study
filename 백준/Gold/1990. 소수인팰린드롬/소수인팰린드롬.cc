#include <iostream>
#include <string>
#include <math.h>
using namespace std;

// 숫자를 받아 펠린드롬인지 확인하는 함수. 맞으면 true를 리턴함
bool IsPelindrome(int num) {
	string number = to_string(num);

	int mid_size = number.length() / 2;

	for (int i = 0; i <= mid_size; i++) {
		if (number[i] != number[number.size() - 1 - i]) {
			return false;
		}
	}

	return true;
}

// 숫자를 받아 소수인지 확인하는 함수. 맞으면 true를 리턴함
bool IsPrime(int num) {
	// 수학적 증명에 의해 num이 소수인지 판별하려면, 2~sqrt(num)까지 나눠보면 된다고함
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) return false;
	}

	return true;
}

int main() {
	int a, b;
	cin >> a >> b;

	for (int i = a; i <= b; i++) {
		if (i > 10000000) break; // a=5, b=100,000,000을 입력해 출력해보면 9989899 이후로는 존재하지 않아 쳐냄
		if (IsPelindrome(i) && IsPrime(i)) {
			cout << i << endl;
		}
	}
	cout << -1;

}