#include <iostream>

using namespace std;

int main() {
    char ch;
    cin >> ch;

    for (int i = -3; i <= 3; i++) {
        char tmp = (char)(ch + i);
        // 만약 범위에서 벗어난 경우
        if (tmp < 'A') {    
            cout << char(tmp + 26);
        }
        else if (tmp > 'Z') {
            cout << char(tmp - 26);
        }
        else {
            cout << tmp;
        }
    }

    return 0;
}