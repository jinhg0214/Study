#include <iostream>
#include <string>

using namespace std;

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	bool arr[1000] = { 0 };
	int N;
	int num, strike, ball;

	// 1. 조건에 맞는 123~987 사이의 가능성 있는 숫자 표시
	for (int i = 123; i <= 987; i++) {
		arr[i] = 1;
	}

	for (int i = 123; i <= 987; i++) {
		int first = i / 100;
		int second = (i / 10) % 10;
		int third = i % 10;
		// 숫자가 0이라면 제외함. 1~9로만 이루어짐
		if (first == 0 || second == 0 || third == 0) {
			arr[i] = 0;
		}
		// 서로 다른 수 이므로, 같은 수는 제외함
		if (first == second || first == third || second == third) {
			arr[i] = 0;
		}
	}

	cin >> N;
	// 2. 배열에 저장된 수의 strike, ball을 체크. 
	// 이 수의 strike, ball이 주어진 strike, ball과 일치하면 놔두고, 아니라면 0으로 바꿈
	while (N--) {
		cin >> num >> strike >> ball;

		for (int i = 123; i <= 987; i++) {
			int strike_cnt = 0;
			int ball_cnt = 0;

			if (arr[i]) {
				string one = to_string(num);
				string two = to_string(i);

				// 두 숫자를 비교하여 strike, ball 판별
				for (int x = 0; x < 3; x++) {
					for (int y = 0; y < 3; y++) {
						// 자리가 같고, 숫자도 같으면
						if (x == y && one[x] == two[y]) {
							strike_cnt++;
						}
						// 자리는 다른데 숫자는 같은경우
						if (x != y && one[x] == two[y]) {
							ball_cnt++;
						}
					}
				}
				if (strike != strike_cnt || ball != ball_cnt) {
					arr[i] = false;
				}
			}
		}
	}

	int result = 0;
	for (int i = 123; i <= 987; i++) {
		if (arr[i]) {
			result++;
		}
	}
	cout << result << endl;
	return 0;
}

/*


풀이 : 
1. 우선 1~9로 이루어진 세 자리 수를 순열을 통해 모두 구하기. 
	조건) 숫자는 1~9로 구성된 모두 다른 수. (123~987 중 120, 111, 112, 131 등과 같은 수 제외)
2. 한 번 물어볼 때마다 위에서 구한 숫자 리스트 중 스트라이크, 볼 개수가 맞지 않는 수를 리스트에서 제거
*/