#include <iostream>
#include <string>

using namespace std;

string arr[5] = {
	"BTS",
	"SBS",
	"BS",
	"CBS",
	"SES"
};

string target;

int cnt = 0;

void DFS(string str) {

	if (str.length() > target.length()) return;

	if (str == target) {
		cout << cnt;
		return;
	}

	for (int x = 0; x < 5; x++) {

		cnt++;
		str += arr[x];

		DFS(str);

		// 원상복구
		int idx = str.length() - 1 - arr[x].length();
		if (idx == -1) idx = 0;
		str.erase(idx, arr[x].length());
		cnt--;
	}

}

int main() {
	cin >> target;

	DFS("");

	return 0;
}