#include <iostream>
#include <string.h>

using namespace std;

struct robot {
	int a;
	int b;
	char t[7];
};

int main() {
	int n, m;
	char str[7];
	robot* p = new robot;

	cin >> n >> m >> str;

	p->a = n;
	p->b = m;
	strcpy(p->t, str);
 
	cout << p->a + p->b << " " << p->t;
}