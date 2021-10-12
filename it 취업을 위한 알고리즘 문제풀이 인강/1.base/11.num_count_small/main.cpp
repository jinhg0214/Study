#include <stdio.h>

// int to char?
// %을 이용하면 더 쉽게 풀이 가능

int main(){
    int n, cnt=0, tmp;

    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        tmp=i;

        // 자리수 분리
        while(tmp > 0){
            tmp = tmp/10;
            cnt++;
        }
    }
    printf("%d",cnt);

    return 0;
}
