#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int map[10][10];
int mask[10][10];
int dat[10];

void Input() {
	freopen_s(new FILE*, "test.txt", "r", stdin);

	cin >> n;

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> map[y][x];
		}
	}

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> mask[y][x];
		}
	}
}

bool compare(int front, int back) {
	// 빈도수가 높을수록
	if (dat[front] < dat[back]) return false;
	if (dat[front] > dat[back]) return true;

	// 숫자가 작을수록
	return front < back;
	
}

int main() {

	Input();

	vector<int> result;

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++){
			if (mask[y][x] == 1) {
				result.push_back(map[y][x]);
				dat[map[y][x]]++;
			}
		}
	}

	sort(result.begin(), result.end(), compare);

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}

	return 0;
}