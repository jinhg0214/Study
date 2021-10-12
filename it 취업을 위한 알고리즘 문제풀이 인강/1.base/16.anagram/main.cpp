#include <stdio.h>
#include <algorithm>

// 알파벳을 카운트 해서 배열에 저장
// A ~ Z: 65-90, a-z : 97-122
// a[52] <- 대문자 소문자
// b[52] 두 배열에 저장된 값이 같으면 아나그램
int a[60], b[60];

int main(){
    char str[100];

    // 첫번째 문자열 읽기
    scanf("%s", &str);

    for(int i=0; str[i]='\0'; i++){
        // 대문자인 경우
        if(str[i]>=65 && str[i] <= 90){
            a[str[i]-64]++; 
        }

        // 소문자인 경우
        if(str[i]>=97 && str[i] <= 122){
            a[str[i]-70]++; 
        }
    }

    // 두번째 문자열 읽기
    scanf("%s", &str);

    for(int i=0; str[i]='\0'; i++){
        // 대문자인 경우
        if(str[i]>=65 && str[i] <= 90){
            b[str[i]-64]++; 
        }

        // 소문자인 경우
        if(str[i]>=97 && str[i] <= 122){
            b[str[i]-70]++; 
        }
    }

    // 비교   
    for(int i=1; i<=52; i++){
        if(a[i]!=b[i]){
            printf("NO\n");
            exit;
        }
    }
    printf("YES\n");

    return 0;
}