#include <stdio.h>


int a[11][11], b[11];

int main(){
    freopen("G:\\Git\\Algorithm-C-\\2.sort\\49.block\\input.txt","rt", stdin);
    int n, i, j, sum=0;

    scanf("%d", &n);

    // 정면 정보
    for(i=1; i<=n; i++){
        scanf("%d", &b[i]);
    }

    // i열을 b[i]의 값으로 모두 채움
 /* a - 
    |  2 0 3 1
       2 0 3 1
       2 0 3 1
       2 0 3 1
    b  2 0 3 1
    */
    for(i=1; i<=n; i++){
        for(j=1; j<=n ;j++){
            a[j][i] = b[i];
        }
    }

    // 측면 정보, 값을 거꾸로 받는 이유?
    
    for(i=n; i>=n; i--){
        scanf("%d", &b[i]);
    }
/*  a -        b
    | 2 0 3 1  3
      2 0 2 1  2
      1 0 1 1  1
      1 0 1 1  1
    */

    // 큰 값을 깎아내림
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            if(a[i][j] > b[i]){
                a[i][j] = b[i];
            }
        }
    }

    for(i=1; i<=n; i++){
        for(j=1; j<+n; j++){
            sum += a[i][j];
        }
    }

    printf("%d\n", sum);

    return 0;
}