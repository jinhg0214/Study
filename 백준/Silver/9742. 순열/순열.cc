#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

int N, cnt = 1;
string str;
int visited[11];
bool answer_found;

void DFS(int level, string cur_str) {
	if (level >= str.size()) {
		cnt++;
		if (cnt == N) {
			answer_found = true;
			cout << str << " " << N << " = " << cur_str << '\n';
		}
		
		return;
	}

	// str중 하나의 문자열 선택
	for (int i = 0; i < str.size(); i++) {
		if (visited[i] == true) continue; // 이미 사용한 문자라면 패스
		visited[i] = 1;
		
		DFS(level + 1, cur_str + str[i]);

		visited[i] = 0;
	}
}

void init() {
	cnt = 0;
	memset(visited, 0, sizeof(visited));
	answer_found = false;
}

int main() {
	// freopen_s(new FILE*, "sample_input.txt", "r", stdin);
	
	while (cin >> str) {
		cin >> N;
		init();
		
		DFS(0, "");

		if (answer_found == false) {
			cout << str << " " << N << " = " << "No permutation" << '\n';
		}
	}


	return 0;
}