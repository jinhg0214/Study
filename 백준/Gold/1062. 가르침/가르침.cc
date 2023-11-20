#include <iostream>
#include <string>
#include <vector>


using namespace std;

int N, K;
int alpha[26]; // 배운 알파벳을 저장하는 배열
int answer = 0;
string path;
vector<string> words;

// 현재 생성한 path 문자열로 word에 몇개를 읽을 수 있는지 
int CheckWord(string path) {
	bool flag;
	int cnt = 0;
	// 이 문자가 배운적이 없는 문자인지를 체크

	for (string str : words) {
		flag = true;
		
		for (char ch : str) {
			// 문자열을 하나씩 지울 필요 없이 Direct Index Table 에서 배운 단어인지를 바로 확인한다
			if (alpha[(int)(ch - 'a')] == 0) {
				flag = false;
				break;
			}
		}
		if (flag == true) {
			cnt++;
		}
	}

	return cnt;
}

void DFS(int level, int start, string path) {
	if (level == K - 5) {
		answer = max(answer, CheckWord(path));
		return;
	}

	for (int i = start; i < 26; i++) {
		if (alpha[i] == 1) continue; // 이미 배운 단어
		
		char ch = (char)('a' + i);
		alpha[i] = 1; // 배웠음
		path.push_back((char)('a' + i));

		DFS(level + 1, i, path);

		alpha[i] = 0;
		path.pop_back();
	}

}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> K;

	if (K < 5) {
		cout << 0;
		return 0;
	}
	else if (K == 26) {
		cout << N;
		return 0;
	}

	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		words.push_back(tmp);
	}

	// anta tica 를 읽기 위한 기본 5개 알파벳
	alpha[(int)('a' - 'a')] = 1;
	alpha[(int)('n' - 'a')] = 1;
	alpha[(int)('t' - 'a')] = 1;
	alpha[(int)('i' - 'a')] = 1;
	alpha[(int)('c' - 'a')] = 1;

	DFS(0, 0, "");
	cout << answer;

	return 0;
}