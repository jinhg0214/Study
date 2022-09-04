#include <iostream>

using namespace std;

int main() {
	// freopen_s(new FILE*, "sample_input.txt", "r", stdin);

	// 소수점 아래 첫째자리까지 출력
	cout << fixed;
	cout.precision(1);

	int T, N, C;
	double G;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N;
		int total_C = 0;
		float total_G = 0.0;
		for (int j = 0; j < N; j++) {
			cin >> C >> G;
			total_C += C;
			total_G += G * C;
		}

		cout << total_C << " " << total_G / total_C << endl;
	}
	

	return 0;
}