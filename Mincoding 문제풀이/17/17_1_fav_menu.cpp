#include <iostream>
using namespace std;

bool isExist(char str[], char ch) {

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            return true;
        }
    }

    return false;
}

int main()
{
    char str[5] = "MTKC";

    char ch;

    cin >> ch;

    if (isExist(str, ch)) {
        cout << "발견";
    }
    else {
        cout << "미발견";
    }


    return 0;
}