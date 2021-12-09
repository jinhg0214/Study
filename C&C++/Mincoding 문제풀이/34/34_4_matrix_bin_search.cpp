// 2중 binSearch
#include <iostream>
#include <vector>

using namespace std;

int n;
vector< vector<char> > vect;
int y, x;

int binSearch(int start, int end, int type) {
	int Max = -1;

	// 타입이 0이면 y축 검색
	if (type == 0) {

		while (1) {
			int mid = (start + end) / 2;
			if (start > end)break;

			if (vect[mid][0] == '#') {
				if (Max < mid) {
					Max = mid;
					start = mid + 1;
				}
			}
			else {
				end = mid - 1;
			}
		}
	}
	// type이 0이면 x축 탐색
	else{

		while (1) {
			int mid = (start + end) / 2;
			if (start > end)break;

			if (vect[y][mid] == '#') {
				if (Max < mid) {
					Max = mid;
					start = mid + 1;
				}
			}
			else {
				end = mid - 1;
			}
		}
	}
	

	return Max;
}

void Init() {
	
	cin >> n;

	vect.assign(n, vector<char>(n,0));
	// 입력
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> vect[y][x];
		}
	}
}

int main() {
	freopen_s(new FILE*, "test.txt", "r", stdin);
	Init();

	// y축 binSearch후,
	y = binSearch(0, n - 1, 0);

	// 찾은 y축에서 x축 binSearch
	x = binSearch(0, n - 1, 1);

	cout << y << " " << x;
	return 0;
}