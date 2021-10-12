#include <iostream>

using namespace std;

int main() {
    char input[4][6];

    // 최대 5글자인 문장 4개 받기
    for (int i = 0; i < 4; i++) {
        cin >> input[i];
    }

    

    // 두번 for문 돌아서 풀었음. 다른 좋은 방법이 있을까??? 
    int flag_a = 0, flag_b = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; input[i][j] != '\0'; j++) {
            if (input[i][j] == 'A') {
                flag_a = 1;
                break;
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; input[i][j] != '\0'; j++) {
            if (input[i][j] == 'B') {
                flag_b = 1;
                break;
            }
        }
    }

    
    // A && B가 모두 존재하면 대발견
    // A || B가 존재하면 중발견
    // A, B가 존재하지 않으면 미발견
    if (flag_a && flag_b) {
        cout << "대발견" << endl;
    }
    else if (flag_a || flag_b) {
        cout << "중발견" << endl;
    }
    else {
        cout << "미발견" << endl;
    }
 
    return 0;
}