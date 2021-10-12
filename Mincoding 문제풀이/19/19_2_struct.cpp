#include <iostream>

using namespace std;

struct Data {
	int x, y, z;
};
int main() {
	Data a, b;

	cin >> a.x >> a.y >> a.z;
	cin >> b.x >> b.y >> b.z;

	cout << a.x + b.x << endl
		<< a.y + b.y << endl
		<< a.z + b.z << endl;

	return 0;
}