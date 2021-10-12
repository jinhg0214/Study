#include <iostream>

using namespace std;

void CountLine(char arr[][10]) {
    int cnt;

    for (int i = 0; i < 3; i++) {
        cnt = 0;
        for (int j = 0; arr[i][j] != '\0'; j++) {
            cnt++;
        }
        cout << cnt << "=" << arr[i] << endl;
    }
}

int main() {
    char input[3][10];

    for (int i = 0; i < 3; i++) {
        cin >> input[i];
    }

    CountLine(input);

    return 0;
}