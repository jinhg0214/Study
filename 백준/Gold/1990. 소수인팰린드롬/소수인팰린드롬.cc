#include <iostream>
#include <string>
#include <cmath>

using namespace std;


// 펠린드롬 판별 함수
bool IsPelindrome(int num) {
	string tmp = to_string(num);
	// 한자리는 무조건 펠린드롬임
	if (tmp.size() == 1) {
		return true;
	}

	// 두자리부터는 체크 들어감
	int mid = tmp.length() / 2;

	for (int i = 0; i < mid; i++) {
		if (tmp[i] != tmp[tmp.size() - 1 - i]) {
			return false;
		}
	}

	return true;
}

// 소수 판별 함수
bool IsPrime(int num) {
	if (num < 2) return false;

	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) return false;
	}

	return true;
}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 소수이고 펠린드롬이라면 true
	int a, b;
	cin >> a >> b;

	for (int i = a; i <= 10000000; i++) {
		if (i > b) break;
		if (IsPelindrome(i) && IsPrime(i)) {
			cout << i << endl;
		}
		
	}
	cout << -1;

}

/*
시간 복잡도 계산
각 숫자에 대해  
isPelindrome <- 얼마 안먹음. 문자열을 반으로 쪼개서 끝에서부터 슉슉 같은이 확인하면 끝
isPrime을 수행함 
1. 각 수마다 나누는 방식은 엄청나게 오래걸림
2. 에스토뭐시기의 체를 이용해 먼저 prime을 채워넣는게 빠를듯. 이것도 시간 초과
체를 채우는 과정에서 10^18번 수행해서 시간 초과남 

https://www.acmicpc.net/board/view/1065


소수이면서 펠린드롬인 숫자는 최대값이 10,000,000을 넘지 않는다

이를 이용해 반복문을 돌 때, 천만을 넘어가면 컷 하는 방식으로 하면 시간 초과를 줄일 수 있다고 함...


3. 펠린드롬 숫자를 먼저 구하고,
그 숫자들에 대해 소수 판정 진행 

또한 에라토스테네스 체를 구할 때,  n 이하의 소수를 구할 때 효율적으로 sqrt(n)까지만 구하면 된다고 함
증명 : https://nahwasa.com/entry/%EC%97%90%EB%9D%BC%ED%86%A0%EC%8A%A4%ED%85%8C%EB%84%A4%EC%8A%A4%EC%9D%98-%EC%B2%B4-%ED%98%B9%EC%9D%80-%EC%86%8C%EC%88%98%ED%8C%90%EC%A0%95-%EC%8B%9C-%EC%A0%9C%EA%B3%B1%EA%B7%BC-%EA%B9%8C%EC%A7%80%EB%A7%8C-%ED%99%95%EC%9D%B8%ED%95%98%EB%A9%B4-%EB%90%98%EB%8A%94-%EC%9D%B4%EC%9C%A0

*/ 