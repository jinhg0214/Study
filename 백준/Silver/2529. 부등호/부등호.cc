/*
## 1. 간단 설명

부등호 관계를 만족시키는 정수

부등호 기호 앞뒤에 넣을 수 있는 숫자는 0부터 9까지의 정수이며 선택된 숫자는 모두 달라야 한다

3 < 4 < 5 < 6 > 1 < 2 < 8 > 7 < 9 > 0

부등호 기호를 제거한 뒤, 숫자를 모두 붙이면 하나의 수를 만들 수 있는데 

이 수를 주어진 부등호 관계를 만족시키는 정수

그런데 주어진 부등호 관계를 만족하는 정수는 하나 이상 존재

5 < 6 < 8 < 9 > 0 < 2 < 3 > 1 < 7 > 4

제시된 k개의 부등호 순서를 만족하는 (k+1)자리의 정수 중에서 최댓값과 최솟값 구하기

 { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }중에서 선택해야 하며 선택된 숫자는 모두 달라야 한다.

 # 필요 변수 

 used[10] <- 0123456789 가 사용되었는지 체크하는 변수
 int max_val, min_val <- 부등호 관계를 만족시키는 정수의 최대 최소값

 98 7654 3210 -> int형으로 처리 불가!

string sign = "" <- 부등호를 저장할 문자열

재귀를 호출하면서 부등호 관계가 만족하지 않으면 바로 쳐내기

재귀 함수 (int level, int sign, int num)
	만약 부등호 관계가 만족하지 않는다면 리턴
	만약 모든 부등호를 사용했다면 결과 비교
		최대값 갱신
		최소값 갱신
	0~9까지 수 중에 사용하지 않은 수 선택
	이 수를 사용 표시 체크하고, 부등호 관계를 만족하는 정수의 맨 뒷자리에 추가하기
	
	재귀 호출

	선택해제
	맨뒷자리 빼기


### 입력

첫 줄에 부등호 문자의 개수를 나타내는 정수 k가 주어진다. 그 다음 줄에는 k개의 부등호 기호가 하나의 공백을 두고 한 줄에 모두 제시된다. k의 범위는 2 ≤ k ≤ 9 이다.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

int k;
string sign;
bool used[11];

long long int max_val = -21e10, min_val = 21e10;

// 부등호 관계를 만족시키는 정수인지 체크하는 함수
bool check(string num) {

	for (int i = 0; i < k; i++) {
		//i와 i+1에 부등호를 넣어봄
		int tmp1 = (num[i] - '0');
		int tmp2 = (num[i + 1] - '0');
		
		if (sign[i] == '<' && (tmp1 >= tmp2)) {
			return false;
		}
		else if(sign[i] == '>' && (tmp1 <= tmp2)){
			return false;
		}
	}
	return true;
}

void recursive(int level, string num) {
	if (level == k+1) {
		if (check(num)) {
			long long int n = stoll(num);
			min_val = min(min_val, n);
			max_val = max(max_val, n);
		}
		return;
	}

	for (int x = 0; x <= 9; x++) {
		if (used[x] == 1) continue;
		used[x] = true;
		num.push_back(x + '0');
		recursive(level + 1, num);
		used[x] = false;
		num.pop_back();
	}

}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> k;
	
	for (int i = 0; i < k; i++) {
		char ch; cin >> ch;
		sign.push_back(ch);
	}

	recursive(0, "");

	cout << setw(k + 1) << setfill('0') << max_val << '\n';
	cout << setw(k + 1) << setfill('0') << min_val << '\n';

	return 0;
}