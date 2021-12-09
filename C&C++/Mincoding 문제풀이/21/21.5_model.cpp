#include <iostream>
#include <string>

using namespace std;

struct Model {

	int y, x;

	void Up() {
		y--;
	}
	void Down() {
		y++;
	}
	void Left() {
		x--;
	}
	void Right() {
		x++;
	}
};

int main() {
	// 각 모델들의 초기 위치 설정
	Model A, T, K;
	A = { 2,0 };
	T = { 2,1 };
	K = { 2,2 };

	// 7번의 지령 받기
	string who, cmd;

	for (int i = 0; i < 7; i++) {
		cin >> who >> cmd;

		if (who == "A") {
			if (cmd == "UP") {
				A.Up();
			}
			else if (cmd == "DOWN") {
				A.Down();
			}
			else if (cmd == "LEFT") {
				A.Left();
			}
			else if (cmd == "RIGHT") {
				A.Right();
			}
		}

		else if (who == "T") {
			if (cmd == "UP") {
				T.Up();
			}
			else if (cmd == "DOWN") {
				T.Down();
			}
			else if (cmd == "LEFT") {
				T.Left();
			}
			else if (cmd == "RIGHT") {
				T.Right();
			}
		}

		else if (who == "K") {
			if (cmd == "UP") {
				K.Up();
			}
			else if (cmd == "DOWN") {
				K.Down();
			}
			else if (cmd == "LEFT") {
				K.Left();
			}
			else if (cmd == "RIGHT") {
				K.Right();
			}
		}
	}

	char map[5][3] = {
		'_','_','_',
		'_','_','_',
		'_','_','_',
		'_','_','_',
		'_','_','_'
	};

	map[A.y][A.x] = 'A';
	map[T.y][T.x] = 'T';
	map[K.y][K.x] = 'K';

	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 3; x++) {
			cout << map[y][x];
		}
		cout << endl;
	}
	

	return 0;
}