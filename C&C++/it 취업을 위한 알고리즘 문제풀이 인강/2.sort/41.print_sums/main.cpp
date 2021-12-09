#include <stdio.h>

/*
15
1) 1 2 (2개로 가능한가)
(15-(1+2))/2 = 6
6+1, 6+2

2) 1 2 3 (3개로 가능한가)
(15-(1+2+3))/3 = 3
1+3, 1+4, 1+5

3) 1 2 3 4
(15-(1+2+3+4))/4 = X

4)

*/


int main(){
    int a, b=1, cnt=0, tmp, i;

    scanf("%d", &a);

    tmp = a;

    a = a-1;

    while(a>0){
        b++;    // 개수
        a=a-b;  // 개수를 뺀 뒤 나누어볼 수 

        if(a%b==0){ // 나누어지면,
            for(i=1; i<b; i++){
                printf("%d + ", (a/b)+i);    // i개 더해서 출력
            }
            printf("%d = %d\n", (a/b)+i, tmp); // 마지막 수 
            cnt++;
        }
    }
    printf("%d", cnt);

    return 0;
}