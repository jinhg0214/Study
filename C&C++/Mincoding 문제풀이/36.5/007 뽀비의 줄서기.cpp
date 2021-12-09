#include <iostream>
#include <vector>
#include <string>

using namespace std;

int a, b;
string names[6] = {
	"거북이",
	"쥐",
	"토끼",
	"원숭이",
	"뽀삐",
	"덕구"
};

vector<string> path;
int used[6];
int cnt = 0;

void Input() {
	cin >> a >> b;
}

void DFS(int Lv) {

	if (Lv == a && path[Lv-1] == "뽀삐") return;
	if (Lv == b && path[Lv-1] == "뽀삐") return;

	if (Lv == 6) {
		cnt++;
		return;
	}
	for (int x = 0; x < 6; x++) {
		if (used[x] == 1)continue;
		used[x] = 1;
		path.push_back(names[x]);

		DFS(Lv + 1);

		path.pop_back();
		used[x] = 0;
	}

}


int main() {
	// freopen_s(new FILE*, "test.txt", "r", stdin);
	Input();

	DFS(0);

	cout << cnt;

	return 0;
}