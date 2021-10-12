#include <iostream>
#include <string.h>

using namespace std;

int main(){
    char str[3][15];
    int max = 0, idx=0;

    for (int i = 0; i < 3; i++) {
        cin >> str[i];
        
        // 가장 긴 문자열의 인덱스를 저장
        if (max < strlen(str[i])) {
            max = strlen(str[i]);
            idx = i;
        }
    }

    // 첫번째 문장과 가장 긴 문장 교환
    char tmp[15];
    strcpy(tmp, str[0]);
    strcpy(str[0], str[idx]);
    strcpy(str[idx], tmp);

    for (int i = 0; i < 3; i++) {
        cout << str[i] << endl;
    }



    


    return 0;
}