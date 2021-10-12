#include <stdio.h>

int main(){
    freopen("G:\\Git\\Algorithm-C-\\2.sort\\33.thrid_score\\input.txt", "rt", stdin);

    int a[101], n, i, j, idx, tmp, cnt;

    scanf("%d", &n);

    for(i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    // a[i]를 선택정렬
    for(i=0; i<n; i++){
        idx = i;

        for(j=i; j<n; j++){
            if(a[j] > a[idx]){
                idx = j;
            }
        }
        // swap
        tmp = a[i];
        a[i] = a[idx];
        a[idx] = tmp;
    }

    // 순위 카운팅
    cnt = 0;

    for(i=0; i<n; i++){

        if(a[i] != a[i+1]) cnt++;

        if(cnt==3){
            printf("%d ", a[i]);
            break;
        }
    }

    return 0;
}