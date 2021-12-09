/*
lt cur rt
 ↓ ↓ ↓
0 0 0 1
0 0 0 2
0 0 0 3
 ...
0 0 3 0
0 0 3 1
0 0 3 2 
 ...
0 1 3 0
0 1 3 1
 ...
5 3 6 7

경우의 수를 이용하여 해결

1] cur = 10의 자리
1) 10의 자리가 3보다 큰 경우 경우
5 3 6 7

0 0 3 x
0 1 3 x
 ...
5 3 3 x 
=> 0~53까지 54개의 경우에 10개씩 나타남 54 * 10 = 540 가지
=> (lt+1) * 10

2) 10의 자리가 3보다 작은 경우
5 3 2 7

0 0 3 x
...
5 3 2 x

=> lt * 10

3) 10의 자리가 3인 경우
5 3 3 7 

5 3 3 (0~7)
=> lt * 10 + (rt+1)

...

2] cur = 천의 자리
    5 3 6 7 
    cur = 5
    rt = 367
    k = 1000

3 0 0 0 
    ...
3 9 9 9 => 1000개

(lt+1)*K 
lt*K
lt*K + (rt+1)

k=1

while(lt != 0){
    lt = n / (k*10);
    cur = (n/k)%10;
    rt = n % k;

    if(cur > 3){res += (lt+1)*k;}
    else if (cur < 3){ res += lt*k; }
    else {res += lt*k + (rt+1); }
}


*/

#include <stdio.h>

int main(){
    int n, k, lt = 1, cur, rt, res = 0;
    scanf("%d", &n);

    k = 1;

    while(lt != 0){
        lt = n/(k*10);
        cur = (n/k)%10;
        rt = n % k;

        if(cur > 3){
            res += (lt+1)*k;
        } else if(cur < 3){
            res += lt*k;
        } else {
            res += lt*k + (rt+1);
        }
        k = k*10;
    }

    printf("%d", res);

    return 0;
}