#include <iostream>

using namespace std;

struct node {
	int x;
	node* next;
};

int main() {

	node a, b, c;
	a.x = 3;
	a.next = &b;

	b.x = 5;
	b.next = &c;
	
	c.x = 4;
	c.next = NULL;

	return 0;
}