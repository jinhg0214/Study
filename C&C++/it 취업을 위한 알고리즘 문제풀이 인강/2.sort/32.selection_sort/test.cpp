#include <stdio.h>

int main(){
    int n, a[101], i, j, idx, tmp;

    scanf("%d", &n);

    for(i=0;i<n;i++){
        scanf("%d", &a[i]);
    }

    for(i=0; i<n; i++){
        idx = i;

        // i~n 값중 가장 작은 값 찾기
        for(j=i; j<n; j++){
            if(a[j] < a[idx]){
                idx = j;
            }
        }

        // 맨 앞자리와 swap
        tmp = a[i];
        a[i] = a[idx];
        a[idx] = tmp;
    }

    for(i=0; i<n; i++){
        printf("%d ", a[i]);
    }

}