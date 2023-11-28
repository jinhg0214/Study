#include <iostream>
#include <algorithm>
using namespace std;

int seed_money;
int Y;
int answer = 0;

void DFS(int money, int year) {
	if (year > Y) return;
	if (year == Y) {
		answer = max(answer, money);
		return;
	}
	
	DFS(int(money * 1.35), year + 5);
	DFS(int(money * 1.20), year + 3);
	DFS(int(money * 1.05), year + 1);

}

int main() {
	cin >> seed_money >> Y;
	
	DFS(seed_money, 0);

	cout << answer;
	return 0;
}
