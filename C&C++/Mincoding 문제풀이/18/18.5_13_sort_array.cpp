#include <iostream>

using namespace std;

int main() {
    char input[2][6] = { "DATAW", "BBQK" };

    int n;

    cin >> n;

    // 입력받은 숫자가 홀수면 윗줄 정렬
    // 짝수면 아랫줄 정렬

    char tmp;
    // 홀수인 경우
    if (n % 2 != 0) {
        //윗줄 정렬, 선택정렬
        for (int i = 0; i < 5; i++) {
            for (int j = i; j < 5; j++) {
                if (input[0][i] > input[0][j]) {
                    tmp = input[0][i];
                    input[0][i] = input[0][j];
                    input[0][j] = tmp;
                }
            }
        }
    }
    // 짝수인 경우 
    else {
        // 아랫줄 정렬, 마찬가지로 선택정렬
        for (int i = 0; i < 4; i++) {
            for (int j = i; j < 4; j++) {
                if (input[1][i] > input[1][j]) {
                    tmp = input[1][i];
                    input[1][i] = input[1][j];
                    input[1][j] = tmp;
                }
            }
        }

    }

    for (int i = 0; i < 2; i++) {
        cout << input[i] << endl;
    }

    return 0;
}