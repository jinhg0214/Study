#include <iostream>
#include <vector>
#include <numeric>

#define MAX 101

using namespace std;

int n;
long long int res = 0; // 100 999999 999999 ... 999999
vector<int> v;
int arr[MAX];
bool check[MAX];

void combination(int level, int start) {
	if (level == 2) {
		// 고른 두개의 수의 gcd를 res에 더한다
		res += gcd(arr[0], arr[1]);
		return;
	}
	for (int i = start; i < n; i++) {
		if (check[i] == true) continue;
		check[i] = true;

		arr[level] = v[i];
		combination(level + 1, i);

		check[i] = false;
	}
}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);

	int T; cin >> T;
	while (T--) {
		res = 0;
		v.clear();

		cin >> n;
		for (int i = 0; i < n; i++) {
			int tmp; cin >> tmp;
			v.push_back(tmp);
		}

		// 2개 조합
		combination(0, 0);

		cout << res << '\n';
	}

	return 0;
}