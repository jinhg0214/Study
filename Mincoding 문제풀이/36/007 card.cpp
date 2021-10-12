#include <iostream>
#include <string>

using namespace std;

string cards;

int path[6];
int cardAmount[10]; // dat 이용

int odd = 0, even = 0;

void DFS(int Lv) {

	if (Lv == 4) { // 바닥조건: 카드 4개를 다 뽑은 경우, 홀짝 판별
		if (path[3] % 2 == 0) {
			even++;
		}
		else{
			odd++;
		}

		/*for (int i = 0; i < Lv; i++) {
			cout << path[i];
		}cout << endl;*/

		return;
	}

	// 1~9번 카드중에 개수가 남아있는걸 뽑는다
	for (int x = 1; x <= 9; x++) {
		if (cardAmount[x] == 0) continue;

		cardAmount[x]--;
		path[Lv] = x; 

		DFS(Lv + 1);

		// 원상복귀
		path[Lv] = 0;
		cardAmount[x]++;
	}
}

int main() {

	cin >> cards;
	for (int i = 0; i < 6; i++) { // DAT 
		cardAmount[cards[i] - '0']++;
	}

	DFS(0);

	cout << even + odd << " " << even << " " << odd;

	return 0;
}