#include <stdio.h>

int ch[10]; // 0으로 초기화되어있음

int main(){
    int digit, max = -2147000000, res;
    char a[101]; // 문자로 읽음

    scanf("%s", &a);

    // 자리수 카운팅
    for(int i=0; a[i]!='\0'; i++){
        digit = a[i]-48; // ascii to int
        ch[digit]++;
    }

    // 최대 개수 출력
    for(int i=0; i<=9; i++){
        if(ch[i] > max){
            max = ch[i];
            res = i; // 인덱스 번호 저장
        }
    }

    printf("%d", res);

    return 0;
}