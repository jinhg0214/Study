#include <iostream>
#include <string>

using namespace std;

int main() {
	int N;
	int num = 666 , cnt = 0;
	
	cin >> N;

	while (1) {
		if (cnt == N) break;

		string tmp = to_string(num);

		bool flag = false;
		for (int i = 0; i < tmp.size() - 2; i++) {
			if (tmp[i] == '6') {
				if (tmp[i] == tmp[i + 1] && tmp[i + 1] == tmp[i + 2]) {
					flag = true;
					break;
				}
			}
		}
		num++;
		if (flag) cnt++;
	}
	cout << num - 1;
	return 0;
}