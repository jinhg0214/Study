#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> shelf;
int cnt;

int BinSearch(int start, int end, string target) {
	cnt++;

	if (start > end) return -1;

	int mid = (start + end) / 2;
	if (shelf[mid] == target) {
		return mid;
	}
	else if (shelf[mid] > target) {
		return BinSearch(start, mid - 1, target);
	}
	else {
		return BinSearch(mid + 1, end, target);
	}
}


int main() {
	freopen_s(new FILE*, "test.txt", "r", stdin);
	int n;
	cin >> n;

	
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		shelf.push_back(tmp);
	}

	sort(shelf.begin(), shelf.end(), less<string>());

	int book_n;
	cin >> book_n;

	for (int i = 0; i < book_n; i++) {
		string book_name;
		int sec;
		cin >> book_name >> sec;

		cnt = 0;
		int res = BinSearch(0, shelf.size()-1, book_name);
		if (res != -1 && cnt <= sec) {
			cout << "pass" << endl;
		}
		else {
			cout << "fail" << endl;
		}
	}

	return 0;
}