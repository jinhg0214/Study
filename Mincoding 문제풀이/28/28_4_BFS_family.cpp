// 같은 레벨 출력 -> BFS?
#include <iostream>

using namespace std;

char name[9] = "ABCDEFGH";
int map[8][8] = {
	0,1,1,0,0,0,0,1,
	0,0,0,0,0,0,0,0,
	0,0,0,1,1,0,1,0,
	0,0,0,0,0,1,0,0,
};

struct node {
	int index;
	int level;
} queue[100];

int head = 0, tail = 1;
int level[8]; 

void BFS() {
	queue[0].index = 0;
	queue[0].level = 0;

	while (head != tail) {
		node now = queue[head++];

		level[now.index] = now.level;

		for (int x = 0; x < 8; x++) {
			if (map[now.index][x] == 1) {
				queue[tail].index = x;
				queue[tail].level = now.level + 1;
				tail++;
			}
		}
	}

}

int main() {
	BFS();

	char ch;
	cin >> ch;

	// ch의 레벨을 찾아 
	// 같은 값을 가지는 레벨을 모두 출력 (자기자신은 제외)
	int findLvl = level[ch - 'A'];
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		if (findLvl == level[i] && ch != (char)(i + 'A')) {
			cout << (char)(i + 'A') << " ";
			cnt++;
		}
	}

	if (cnt <= 1) {
		cout << "없음";
	}

	return 0;
}