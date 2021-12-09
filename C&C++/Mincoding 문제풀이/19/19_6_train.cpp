#include <iostream>

using namespace std;

struct Person {
	int win;
	char name[10];
};

// 문자열 비교 함수
bool StrCmp(char a[], char b[]) {
	int a_len=0, b_len=0;

	// 문자열 길이 구하기
	for(int i=0; a[i] != '\0'; i++){
		a_len++;
	}
	for (int i = 0; b[i] != '\0'; i++) {
		b_len++;
	}

	if (a_len != b_len) {
		return false;
	}
	for (int i = 0; i < a_len; i++) {
		if (a[i] != b[i]) {
			return false;
		}
	}
	return true;

}

int main() {
	Person p[7] = {
		{ 15,"summer" },
		{ 33,"cloe" },
		{ 24,"summer" },
		{ 28,"niki" },
		{ 32,"jenny" },
		{ 20,"summer" },
		{ 40,"coco" }
	};

	

	char name[10];
	int age;

	cin >> name >> age;

	for (int i = 0; i < 7; i++) {
		if (StrCmp(p[i].name, name) == true) {
			if (p[i].win == age) {
				cout << i;
			}
		}
	}


	return 0;
}