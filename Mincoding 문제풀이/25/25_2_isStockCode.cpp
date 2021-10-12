#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool strIsStockCode(string str) {
	
	if (str.size() < 6)return false;
	for (int i = 1; i < str.size() - 1; i++) {
		if (str[i] < '0' || str[i] > '9') {
			return false;
		}
	}
	return true;
}

int main() {
	// freopen_s(new FILE*, "test.txt", "r", stdin);

	int n;
	vector<string> news;
	string article;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> article;
		news.push_back(article);
	}
		
	for (int i = 0; i < news.size(); i++) {
		string tmp = news[i];
		string stock_code;

		int start = tmp.find('[');
		int end = tmp.find(']', start + 1);
		
		while (start != string::npos) {
			stock_code = tmp.substr(start, end - start +1);
			
			if (strIsStockCode(stock_code) == true) {
				cout << stock_code << endl;
			}


			start = tmp.find('[', end + 1);
			end = tmp.find(']', end + 2);
		}
		
	
	}


	return 0;
}