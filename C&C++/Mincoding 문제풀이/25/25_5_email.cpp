#include <iostream>
#include <string>

using namespace std;

int main() {
	// freopen_s(new FILE*, "test.txt", "r", stdin);

	string input;

	int a, b;

	cin >> input;

	input += "|";

	a = -1;
	b = input.find('|'); // 첫 시작지점
	while (b != string::npos) {
		string email = input.substr(a+1, b-a-1);
		// cout << email << endl;

		a = input.find('|', a+1);
		b = input.find('|', b+1);

		// email을 id와 domain으로 분리하여 출력한다
		int id_pos = email.find('@');
		string id = email.substr(0, id_pos);
		cout << "[#" << id << "] ";
		
		int domain_pos = email.find('.');
		string domain = email.substr(id_pos + 1, domain_pos - id_pos -1);
		cout << domain << endl;

	}
	

}