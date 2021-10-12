#include <iostream>

using namespace std;

int arr[9] = { 3,1,2,1,3,2,1,2,1 };


void jump(int level) {

	
	if (level >= 10) {
		cout << "도착" << " ";
		return;
	}

	cout << arr[level-1] << " ";
	jump(level + arr[level-1]);
	cout << arr[level - 1] << " ";

}

int main() {
	int n;
	cin >> n;
	
	cout << "시작 ";
	jump(n);
	cout << "시작 ";
}