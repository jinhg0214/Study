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

	// start_point = (1,2) + (1,3) + (1,4) + ... (2,3) + (2,4) + (3,4)
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

void combination(int level, int start) {
	if (level == N / 2) {
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

		combination(level + 1, i + 1);

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

	combination(0, 0);

	cout << min_diff;

	/*
	S_ij -> i와 j가 같은 팀에 속했을때, 팀에 더해지는 능력치

	startteam, linkteam으로 나눠서 능력치 차이를 최소화 하려고 함


	필요 변수

	사람 수 N
	점수 배열 S[N][N];

	각 팀의 점수 start_point, link_point;
	최소값 diff_min
	팀에 속해있는지 체크할 배열 필요 bool used[N]

	1. N_C_(N/2)를 뽑아 start_team 생성, 벡터에 저장
	2. 뽑히지 않은 사람들을 모아 link_team 생성
	3. 각 팀의 포인트 계산
	4. 두 포인트의 차를 계산하여 최소값 갱신
	5. 최소값 출력

	*/

	return 0;
}

