#include <stdio.h>

int main(){
    freopen("G:\\Git\\Algorithm-C-\\1.base\\23.Increasing_sequence\\input.txt", "rt", stdin);

    int n, cnt=1, max=0, pre, now;
    
    scanf("%d", &n);
    
    // 첫번째 값은 직접 읽어줌 
    scanf("%d", &pre);

    for(int i=2; i<= n; i++){
        scanf("%d", &now);
        if(now >= pre){
            cnt++;
            if(cnt > max){
                max = cnt;
            }
        } else cnt = 1;
        pre = now;

    }

    // 출력
    printf("%d", max);

    return 0;
}