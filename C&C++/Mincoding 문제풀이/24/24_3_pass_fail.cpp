#include <iostream>
#include <string>

using namespace std;

int main() {
	string log;

	cin >> log;

	for (int i = 0; i < log.size(); i++) {
		if (log[i] >= 'a' && log[i] <= 'z') {
			log[i] = log[i] - 'a' + 'A';
		}
	}

	// pass cnt
	int pass_cnt = 0;
	int pos = log.find("PASS");
	while (pos != string::npos) {
		pass_cnt++;
		pos = log.find("PASS", pos + 1); // 위치 갱신
	}

	// FAIL cnt
	int fail_cnt = 0;
	pos = log.find("FAIL");
	while (pos != string::npos) {
		fail_cnt++;
		pos = log.find("FAIL", pos + 1); // 위치 갱신
	}

	float pass = pass_cnt;
	float fail = fail_cnt;
	printf("%.f%%", (pass / (pass + fail)) * 100);


	return 0;
}