#include <iostream>
#include <string>

using namespace std;

int main() {
	string input, tmp;
	string notepad[10];
	int idx=0;

	cin >> input;

	for (int i = 0; i < input.size(); i++) {
		
		if (tmp == "_") {
			tmp.clear();
		}

		// _을 만나고, tmp에 내용이 있다면,
		if (input[i] == '_' && tmp.size() !=0) {
			notepad[idx] = tmp;
			tmp.clear();
			idx++;
		}
		else {
			tmp += input[i];
		}
	}
	notepad[idx] = tmp;

	for (int i = 0; i < idx+1; i++) {
		cout << i+1 << "#" << notepad[i] << endl;
	}

	return 0;
}