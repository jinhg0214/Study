#include <iostream>

using namespace std;

int main() {
	int a, b, c, d, e, f;
	scanf("%d:%d:%d", &a, &b, &c);
	scanf("%d:%d:%d", &d, &e, &f);

	d -= a;
	e -= b;
	f -= c;
	if(f<0){
		f += 60; e--;
	}
	if (e < 0) {
		e += 60; d--;
	}
	if (d < 0) {
		d += 24;
	}

	printf("%02d:%02d:%02d", d, e, f);

	return 0;
}