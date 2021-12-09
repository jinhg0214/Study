#include <stdio.h>

int main(){
    int n, cnt = 0, tmp, digit;

    scanf("%d", &n);

    for(int i =1; i<=n; i++){
        tmp = i;
        
        while(tmp>0){
            digit = tmp % 10; // tmp의 일의 자리
            if(digit == 3 ) cnt ++;
            tmp = tmp/10;
        }
    }
    printf("%d", cnt);

    return 0;
}

/*
1. int -> string으로 다 때려넣고 3을 카운트?
2. 직접 카운트 

*/