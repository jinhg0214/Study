#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<string> book;

bool compare(string a, string b) {
	if (a.length() < b.length()) return true;
	else if ((a.length() > b.length())) return false;
	else return a < b;
}

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	string input;
	while (N--) {
		cin >> input;
		book.push_back(input);
	}

	sort(book.begin(), book.end(), compare);
	book.erase(unique(book.begin(), book.end()), book.end());
	


	for (string e : book) {
		cout << e << endl;
	}

	return 0;
}