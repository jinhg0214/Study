#include <stdio.h>

int main(){
    int n, a[101], i, j, tmp;

    scanf("%d", &n);

    for(i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    // 바로 뒤의 원소와 크기를 비교 후, 자리 변경
    for(i=0; i<n-1; i++){

        for(j=0; j<n-i-1; j++){ // 큰 수가 뒤부터 차곡차곡 쌓임
            if(a[j] > a[j+1]){
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }

    for(i=0; i<n; i++){
        printf("%d ", a[i]);
    }

}