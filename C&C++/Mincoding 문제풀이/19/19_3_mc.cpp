#include <iostream>
#include <cstring>

using namespace std;

struct MC {
	char burger1[20];
	char burger2[20];
};

int main() {
	MC bob, tom;

	cin >> bob.burger1 >> bob.burger2;
	cin >> tom.burger1 >> tom.burger2;

	cout << "bob.burger1=" << strlen(bob.burger1) << endl
		<< "bob.burger2=" << strlen(bob.burger2) << endl
		<< "tom.burger1=" << strlen(tom.burger1) << endl
		<< "tom.burger2=" << strlen(tom.burger2) << endl;

	return 0;
}