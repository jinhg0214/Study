#include <iostream>
#include <stack>

using namespace std;

int main() {

	string input;
	cin >> input;

	stack<char> st;
	int result = 0;

	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '(') {
			st.push('(');
		}
		else {
			st.pop();
			if (input[i-1] == '(') {
				result += st.size();
			}
			else {
				result++;
			}
		}
	}
	
	cout << result;

	return 0;
}