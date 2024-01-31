#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define MAX 1001
int lcs[MAX][MAX];

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	string str1, str2;
	cin >> str1 >> str2;

	int n = str1.size();
	int m = str2.size();

	int max_cnt = 0;
	for (int y = 0; y <= m; y++) {
		for (int x = 0; x <= n; x++) {
			if (y == 0 || x == 0) {
				lcs[y][x] = 0;
			}
			else if (str1[x-1] == str2[y-1]) {
				lcs[y][x] = lcs[y - 1][x - 1] + 1;
			}
			else {
				lcs[y][x] = max(lcs[y - 1][x], lcs[y][x - 1]);
			}
			max_cnt = max(max_cnt, lcs[y][x]);
		}
	}
	cout << max_cnt;

	return 0;
}