#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int N;
int p[17][17];
int visited[17];
float max_percentage = 0; // 최대 확률

void Input() {
	N = 0;
	memset(p, 0, sizeof(p));
	memset(visited, 0, sizeof(visited));
	max_percentage = 0.0;

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> p[i][j];
		}
	}
}
/*
double round_digit(double num, int d) {
	double t = pow(10, d - 1);
	return round(num * t) / t;
}*/

// Lv 몇번째 사람 인지, res : 현재까지의 확률
void DFS(int Lv, float res) {
	if (Lv == N+1) { // 바닥조건 : 다 뽑았다면 나오기
		if (max_percentage < res) {
			max_percentage = res;
		}
		return;
	}

	for (int t = 1; t <= N; t++) {
		if (visited[t] == true) { continue; } // 이미 작업이 할당되어있는 경우 패스

		visited[t] = 1;
		DFS(Lv + 1, res * p[Lv][t] / 100.0);
		visited[t] = 0;

	}

}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	cout << fixed;
	cout.precision(6);

	int T, i = 1;
	cin >> T;
	while(T--){
		Input();

		DFS(1, 1);

		cout << "#" << i++ << " " << max_percentage << endl;
	}
	return 0;
}