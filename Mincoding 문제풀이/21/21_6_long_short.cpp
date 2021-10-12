#include <iostream>
#include <string>

using namespace std;

int main() {
	string str[4];
	int max_i= 0, min_i=0;

	for (int i = 0; i < 4; i++) {
		cin >> str[i];
		if (str[i].size() > str[max_i].size()) {
			max_i = i;
		}
		if (str[i].size() < str[min_i].size()) {
			min_i = i;
		}
	}


	cout << "긴문장:" << max_i << endl
		<< "짧은문장:" << min_i;


	return 0;
}