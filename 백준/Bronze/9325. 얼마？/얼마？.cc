#include <iostream>

using namespace std;

int main() {
	// freopen_s(new FILE*, "sample_input.txt", "r", stdin);

	int T, N;
	cin >> T;
	
	for (int t = 1; t <= T; t++) {
		int car_price, sum = 0;
		cin >> car_price >> N;
		for (int i = 0; i < N; i++) {
			int option_no, option_price; 
			cin >> option_no >> option_price;
			sum += option_price * option_no;
		}
		cout << car_price + sum << endl;
	}
		
	return 0;
}