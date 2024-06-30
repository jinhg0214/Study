#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int n;
char matrix[11][11];
bool flag = false;

vector<int> v;

void input() {
	cin >> n;

	for (int y = 0; y < n; y++) {
		for (int x = y; x < n; x++) {
			cin >> matrix[y][x];
		}
	}
}

// 현재 v에 들어있는 원소로 matrix 검증하는 함수
bool check(int level) {

	int sum = 0;
	for (int i = level; i >= 0; i--) {
		sum = sum + v[i];
		
		if (matrix[i][level] == '+' && sum <= 0) return false;
		if (matrix[i][level] == '-' && sum >= 0) return false;
		if (matrix[i][level] == '0' && sum != 0) return false;
	}
	return true;

}

void recursive(int level) {
	if (flag == true) return;
	if (level == n) {
		flag = true;
		for (int e : v) {
			cout << e << ' ';
		}
		return;
	}

	for (int x = -10; x <= 10; x++) {
		v.push_back(x);
		if(check(level) == true)
			recursive(level + 1);
		v.pop_back();
	}
}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	input();

	recursive(0);

	return 0;
}
