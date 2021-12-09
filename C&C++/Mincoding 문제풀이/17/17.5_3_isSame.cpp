#include <iostream>

using namespace std;




bool isSame(char a[], char b[]) {
	// 먼저 문자열의 크기를 비교한다 다르면 바로 거짓!
	int a_len = 0, b_len = 0;

	for (int i = 0; a[i] != '\0'; i++) { a_len++; }
	for (int i = 0; b[i] != '\0'; i++) { b_len++; }

	if (a_len != b_len) return false;

	// 문자열의 크기가 같으면 하나씩 비교한다
	for (int i = 0; i < a_len; i++) {
		if (a[i] != b[i]) {
			return false;
		}
	}
	return true;

}

int main() {
	char name1[10];
	char name2[10];

	cin >> name1 >> name2;

	if (isSame(name1, name2)) {
		cout << "동명";
	}
	else {
		cout << "남남";
	}

	return 0;
}