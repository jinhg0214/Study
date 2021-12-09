#include <iostream>

using namespace std;

int main() {
    char input[2][6];
    char sum[12];

    // 두 문장 입력받기
    for (int i = 0; i < 2; i++) {
        cin >> input[i];
    }

    // 길이 구하기
    int len[2] = { 0 };
    for (int i = 0; i < 2; i++) {
        for (int j = 0; input[i][j] != '\0'; j++) {
            len[i]++;
        }
    }

    int idx_4_sum = 0;

    for (int i = 0; i < len[0]; i++) {
        sum[idx_4_sum] = input[0][i];
        idx_4_sum++;
    }
    
    for (int i = 0; i < len[1]; i++) {
        sum[idx_4_sum] = input[1][i];
        idx_4_sum++;
    }

    sum[idx_4_sum] = '\0';

    cout << sum;


    return 0;
}