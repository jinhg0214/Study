#include <iostream>
#include <string>

using namespace std;

int main() {
	// freopen_s(new FILE*, "sample_input.txt", "r", stdin);

	int T; cin >> T;
	while (T--) {
		int N, M, cnt = 0;
		cin >> N >> M;
		for (int i = N; i <= M; i++) {
			int len = to_string(i).size();
			
			for (int j = 0; j < len; j++) {
				if (to_string(i)[j] == '0') cnt++;
			}
		}
		cout << cnt << endl;;
	}

	return 0;
}