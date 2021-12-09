#include <iostream>
#include <string>

using namespace std;

int main() {
	// freopen_s(new FILE*, "test.txt", "r", stdin);
	int n;
	cin >> n;

	string str[7];
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			string tmp;
			tmp = str[i] + str[j];
			if (tmp == "HITSMUSIC") {
				cnt++;
			}
		}
	}
	cout << cnt;

	return 0;
}