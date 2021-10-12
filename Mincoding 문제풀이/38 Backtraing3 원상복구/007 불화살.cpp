/*
* n을 입력받아 n개의 숫자를 입력받는다.
과녁에 불화살을 쏜다
맞춘 과녁판의 점수를 얻고 위 아래칸은 불타서 없어진다
더이상 맞출 과녁이 없을때까지 이를 반복해서 얻는 최대 점수를 구하라
*/

/*
바닥조건이 특정 Lv에 도달하는게 아닌,
더이상 쏠 과녁이 없는경우 -> used배열에 모두 0이 아닌 값이 들어있는 경우 종료!
또한, used배열을 복구하는 과정에서 
3, 1, 4를 선택한 경우
3을 쏘면 5가 같이 불타 없어지고, 1,7,4가 남은 경우 1을 쏘고, 복구하는 과정에서 5가 다시 살아나게됨
이를 방지하기 위해 used를 증감시키는 방법을 사용함

*/

#include <iostream>
#include <cstring>

using namespace std;

int n;
int target[9];
int used[9];
int path[9];

int res[9];
int max_res = 0;

void Input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> target[i];
	}
}

void Shoot(int Lv, int sum) {

	// 바닥조건: 더이상 쏠 과녁이 없으면 종료
	bool flag = true;
	for (int i = 0; i < n; i++) {
		if (used[i] == 0) {
			flag = false;
			break;
		}
	}
	if (flag == true) {
		if (max_res < sum) {
			memset(res, 0, sizeof(res));
			max_res = sum;
			for (int i = 0; i < Lv; i++) {
				res[i] = path[i];
			}
		}
		return;
	}

	for(int x=0; x<n; x++){
		if (used[x] != 0) continue; // 이미 쐈거나 불탄경우
		// x-1, x, x+1의 used를 1로 바꿔줌 
		if(x-1 >= 0) used[x - 1]++;
		used[x]++;
		if(x+1 <= n-1) used[x + 1]++;

		path[Lv] = target[x];
		Shoot(Lv + 1, sum + target[x]);

		// 원상복구
		path[Lv] = 0;

		if (x - 1 >= 0) used[x - 1]--;
		used[x]--;
		if (x + 1 <= n - 1) used[x + 1]--;
	}


}


int main() {
	// freopen_s(new FILE*, "test.txt", "r", stdin);
	Input();

	Shoot(0, 0);

	for (int i = 0; res[i] != 0; i++) {
		
		if (res[i + 1] != 0) {
			cout << res[i] << "+";
		}
		else {
			cout << res[i] << "=";
		}
	}
	cout << max_res << endl;

	return 0;
}