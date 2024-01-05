#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

#define MAX 2010

int N, M;
vector<vector<int>> lamp_switch;
bool lamp[MAX];

bool compare(vector<int> a, vector<int> b) {
	return a.size() > b.size();
}

void Input() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> M;
	lamp_switch.resize(N);
	for (int i = 0; i < N; i++) {
		int size_for_switch;
		cin >> size_for_switch;
		lamp_switch[i].resize(size_for_switch);

		for (int j = 0; j < size_for_switch; j++) {
			cin >> lamp_switch[i][j];
		}
	}
}

bool Check() {
	for(int i=1; i<=M; i++){
		if (lamp[i] == false) {
			return false;
		}
	}
	return true;
}

int main() {
	Input();

	// i번째 버튼을 제외하고 눌러봄
	for (int i = 0; i < N; i++) {
		memset(lamp, 0, sizeof(lamp)); // 램프 초기화

		// i 번을 제외하고 다 눌러본다
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			for (int k = 0; k < lamp_switch[j].size(); k++) {
				lamp[lamp_switch[j][k]] = true;
			}
		}

		// 모두 켜졌다면
		if (Check()) {
			cout << "1" << endl;
			return 0;
		}
	}

	cout << "0";

	return 0;
}