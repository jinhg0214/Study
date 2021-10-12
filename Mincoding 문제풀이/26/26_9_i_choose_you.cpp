#include <iostream>

using namespace std;

int main() {
	// 문장 입력
	char str[8];

	cin >> str;

	// 인덱스 입력
	int data[4];

	for (int i = 0; i < 4; i++) {
		cin >> data[i];
	}

	// ptr
	char* ptr[4];

	for (int i = 0; i < 4; i++) {
		ptr[i] = &str[data[i]];
	}

	for (int i = 0; i < 4; i++) {
		cout << *ptr[i];
	}

	return 0;
}