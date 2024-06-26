#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int s[21][21];
bool used[21];
vector<int> start_team, link_team;

int min_diff = 21e8;

// 각 팀의 포인트 계산
int PointCheck(vector<int>& start_team, vector<int>& link_team) {
	
	int start_point = 0, link_point = 0;

	for (int elem : start_team) {
		for (int i = 0; i < N; i++) {
			if(used[i]==true){
				start_point += s[elem][i];
			}
		}
	}
	
	for (int elem : link_team) {
		for (int i = 0; i < N; i++) {
			if (used[i] == false) {
				link_point += s[elem][i];
			}
		}
	}

	return abs(start_point - link_point);
}

void combination(int level, int start, int limit) {
	if (level == limit) {
		// start_team에 뽑히지 않은 선수들 link_team에 넣기
		for (int i = 0; i < N; i++) {
			if (used[i] == false) {
				link_team.push_back(i);
			}
		}
		min_diff = min(min_diff, PointCheck(start_team, link_team));

		link_team.clear(); // 계산 후 link_team은 clear해줘야함

		return;
	}

	for (int i = start; i < N; i++) {
		
		used[i] = 1; 
		start_team.push_back(i);

		combination(level + 1, i + 1, limit);

		used[i] = 0;
		start_team.pop_back();
	}
}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N;
	for (int y = 0; y < N; y++){
		for (int x = 0; x < N; x++) {
			cin >> s[y][x];
		}
	}

	for (int limit = 1; limit < N; limit++) {
		combination(0, 0, limit);
	}

	cout << min_diff;

	return 0;
}