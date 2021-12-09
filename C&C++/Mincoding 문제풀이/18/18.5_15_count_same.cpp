#include <iostream>

using namespace std;

int main() {
    char input[2][9];

    // 두 문장 입력받기
    for (int i = 0; i < 2; i++) {
        cin >> input[i];
    }

    // 일단 누가 더 짧은지 확인
    int len[2] = { 0 };
    for (int i = 0; i < 2; i++) {
        for (int j = 0; input[i][j] != '\0'; j++) {
            len[i]++;
        }
    }
    // 짧은만큼만 반복 돌기 위해 짧은쪽을 저장
    int short_len = min(len[0], len[1]); 
    int long_len = max(len[0], len[1]);

    int cnt = 0;
    // 같은 idx에 있지만 다른 글자가 있는지 확인
    for (int i = 0; i < short_len; i++) {
        // 다른 글자수 카운팅
        if (input[0][i] != input[1][i]) {
            cnt++;
        }
    }

    // 만약 더남았으면? 그만큼 추가해줌
    cnt += long_len - short_len;

    cout << cnt;


    return 0;
}