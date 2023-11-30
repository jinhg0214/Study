#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);
	int N;
	cin >> N;
	vector<int> v(N);

	// 표현식 저장
	string str;
	cin >> str;

	// 피연산자에 대응하는 숫자를 저장
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	// 나눗셈을 위해 double로 생성
	stack<double> st;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			st.push(v[str[i] - 'A']);
		}
		else {
			double b = st.top(); st.pop();
			double a = st.top(); st.pop();

			if (str[i] == '+') { a = a + b; }
			else if (str[i] == '-') { a = a - b; }
			else if (str[i] == '*') { a = a * b; }
			else if (str[i] == '/') { a = a / b; }

			st.push(a);
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << st.top();

	return 0;
}
// 주의점 : 피연산자는 100보다 작은 자연수이므로, 두자리수가 될 수 도 있다