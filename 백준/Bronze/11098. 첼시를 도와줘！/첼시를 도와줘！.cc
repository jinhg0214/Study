#include <iostream>
#include <string>

using namespace std;

int main() {
	// freopen_s(new FILE*, "sample_input.txt", "r", stdin);
	int N, P;
	int max_price;
	string max_player;
	int test_case = 1;
	
	cin >> N;
	
	while (test_case <= N) {
		cin >> P;

		max_price = 0;
		max_player = "";
		for (int i = 0; i < P; i++) {
			int tmp_price;
			string tmp_player;
			cin >> tmp_price >> tmp_player;

			if (tmp_price > max_price) {
				max_price = tmp_price;
				max_player = tmp_player;
			}
		}

		cout << max_player << endl;

		test_case++;
	}


	return 0;
}