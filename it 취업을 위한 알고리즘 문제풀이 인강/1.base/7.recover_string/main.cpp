#include <stdio.h>


int main(){
    freopen("G:\\Git\\Algorithm-C-\\1.base\\7.recover_string\\input.txt", "rt", stdin);

    char a[101], b[101];

    int pos = 0;

    // 부분부분 띄어쓰기가 포함되어있으므로 줄로 받아야함
    gets(a);

    // 공백을 제거하고 영어 단어만 b 배열에 저장
    for(int i=0; a[i] != '\0'; i++){
        if(a[i] != ' '){
             // 대문자인 경우
             if(a[i] >= 65 && a[i] <= 90){
                // b[pos] 에 a[i]를 대문자로 변경 후 pos를 1 증가
                b[pos++] = a[i]+32; // A = 65, a = 97
            } 
            // 소문자인 경우 그대로 삽입
            else{
                b[pos++] = a[i];
            }
        }
    }
    // 마지막 pos 지점에 null 삽입
    b[pos] = '\0';

    printf("%s\n", b);

    return 0;
}