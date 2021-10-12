#include <iostream>
#include <string>

using namespace std;

string spam[5] = {
	"chicken",
	"pizza",
	"jockbal",
	"bread",
	"samhap"
};

int main() {
	string input;
	cin >> input;

	for (int i = 0; i < 5; i++) {
		string str = input;

		for (int i = 0; i < input.length(); i++) {
			str[i] = tolower(input[i]);
		}

		int a = str.find(spam[i]);
		if (a == -1) continue;
		
		input.replace(a,spam[i].length(),"###");
	}

	cout << input;

	return 0;
}