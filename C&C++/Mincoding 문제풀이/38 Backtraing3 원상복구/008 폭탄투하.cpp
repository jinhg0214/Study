/*
4*4 문자 배열과 폭탄 개수를 입력받음
폭탄은 중앙,상,하,좌,우로 터질때 
가장 많은 알파벳을 없앨 수 있는 폭탄의 원점을 출력
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int direct[5][2] = { 0,0, -1,0, 0,-1, 1,0, 0,1 };
char char_map[4][4];
int bomb_n;

int map[4][4];
int visited[4][4];
int Max = 0;

vector< pair<int, int> > path;
vector< pair<int, int> > res_path;


void Input() {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			cin >> char_map[y][x];
		}
	}
	cin >> bomb_n;
}

void Init() {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (char_map[y][x] != '_') {
				map[y][x] = 1;
			}
		}
	}
}

int KillCnt() {
	int cnt = 0;
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (visited[y][x] != 0 && char_map[y][x] != '_') {
				cnt++;
			}
		}
	}
	return cnt;
}

void Bomb(int Lv) {

	if (Lv == bomb_n) {
		int res = KillCnt();
		if (Max < res) {
			Max = res;
			res_path = path;
		}
		return;
	}

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
	
			if (visited[y][x] == 0) {
				path.push_back({ y,x });

				for (int t = 0; t < 5; t++) {
					int dy = y + direct[t][0];
					int dx = x + direct[t][1];

					if (dy < 0 || dx < 0 || dy >= 4 || dx >= 4) continue;
					// if (visited[dy][dx] == 1) continue;

					visited[dy][dx]++;
				}

				Bomb(Lv + 1);

				path.pop_back();
				// 원상복구
				for (int t = 0; t < 5; t++) {
					int dy = y + direct[t][0];
					int dx = x + direct[t][1];

					if (dy < 0 || dx < 0 || dy >= 4 || dx >= 4) continue;
					if (visited[dy][dx] == 0) continue;

					visited[dy][dx]--;
				}
			}
		}
	}
}


int main() {
	freopen_s(new FILE*, "test.txt", "r", stdin);
	Input();

	Init();

	Bomb(0);


	vector<char> result;
	for (int i = 0; i < res_path.size(); i++) {
		int y = res_path[i].first;
		int x = res_path[i].second;
		result.push_back(char_map[y][x]);
	}

	sort(result.begin(), result.end(), less<char>());

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}


	return 0;
}