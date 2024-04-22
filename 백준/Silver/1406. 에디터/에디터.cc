#include <iostream>
#include <list>

using namespace std;

int main() {
	// freopen_s(new FILE*, "input.txt", "r", stdin);

	int M;
	string s = "";

	cin >> s;

	list<char> li(s.begin(), s.end()); // 이렇게 생성 가능

	list<char>::iterator cursor;
	cursor = li.end();

	cin >> M;

	while (M--) {
		char cmd, c; cin >> cmd;

		switch (cmd)
		{
		case 'L':
			if (cursor != li.begin())
				cursor--;
			break;
		case 'D':
			if (cursor != li.end())
				cursor++;
			break;
		case 'B':
			if (cursor != li.begin()) {
				cursor--;
				cursor = li.erase(cursor); // 삭제 하고 iterator를 반환하는듯함
			}
			break;
		case 'P':
			cin >> c;
			li.insert(cursor, c); // iter 위치에 삽입
			break;
		}
	}

	for (cursor = li.begin(); cursor != li.end(); cursor++) {
		cout << *cursor;
	}

	return 0;
}