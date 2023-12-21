#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

struct ingredient {
	int sour;
	int bitter;
};

int N;  
int result = 21e8;
bool ingredient_flag = false;
vector<ingredient> gd;
vector<int> used;

void run(int level, long long int sourPoint, long long int bitterPoint){
	// 모든 재료를 다 사용한 경우
	if (!used.empty() && level == N) {
		//cout << abs(sourPoint - bitterPoint) << endl;
		if (abs(sourPoint - bitterPoint) < result) {
			result = abs(sourPoint - bitterPoint);
		}
		return;
	}
	if (level >= N) return;

	used.push_back(level); // 현재 재료를 썼다고 표시
	run(level + 1, sourPoint * gd[level].sour, bitterPoint + gd[level].bitter); // 사용하거나
	used.pop_back();

	run(level + 1, sourPoint, bitterPoint); // 안하거나
	return;
}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N;
	gd.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> gd[i].sour >> gd[i].bitter;
	}

	run(0, 1, 0);

	cout << result;

	return 0;
}