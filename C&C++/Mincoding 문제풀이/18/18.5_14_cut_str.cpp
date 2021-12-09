#include <iostream>

using namespace std;

int main() {

    char arr[3][6] = {
        "POTIO",
        "ABCDE",
        "YOURE"
    };

    int a, b;

    cin >> a >> b;

    int idx = 0;
    char str[18];

    for (int i = 0; i < 3; i++) {
        for (int j = a; j <= b; j++) {
            str[idx] = arr[i][j];
            idx++;
        }
    }
    str[idx] = '\0';

    cout << str;
     

    return 0;
}