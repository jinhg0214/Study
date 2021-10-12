#include <iostream>

using namespace std;

int main() {
    char arr[3][20];

    for (int i = 0; i < 3; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; arr[i][j] != '\0'; j++) {
            if (arr[i][j + 1] == '\0') {
                cout << arr[i][j];
            }
        }
    }


    return 0;
}