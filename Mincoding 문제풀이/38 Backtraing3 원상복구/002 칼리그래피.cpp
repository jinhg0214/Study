#include <iostream>
#include <string>

using namespace std;

string str;
int n;
char path[20];

int max_score = 0;

int PointCalc() {
	int score = 0;
	
	for (int i = 0; i < str.length() - 1; i++) {
		// 1. 이웃한 글자가 같으면 -50점
		if (str[i] == str[i + 1]) {
			score -= 50;
		}
		// 2. 같은 글자는 아닌데, 아스키 코드 간격이 5 이하면 3점
		else if (abs(str[i] - str[i + 1]) <= 5) {
			score += 3;
		}
		// 3. 간격이 20이상이면 10점
		else if (abs(str[i] - str[i + 1]) >= 20) {
			score += 10;
		}
	}

	return score;
}

void Cali(int Lv) {
	if (Lv == n) {
		int result = PointCalc();
		if (max_score < result) {
			max_score = result;
		}

		return;
	}

	for (int i = 0; i < str.length(); i++) {
		for (int j = i; j < str.length(); j++) {
			if (str[i] == str[j]) continue;
			swap(str[i], str[j]);
			Cali(Lv + 1);
			swap(str[i], str[j]);
		}
	}


}

int main() {
	cin >> str >> n;

	Cali(0);

	cout << max_score;

	return 0;
}