#include <stdio.h>

int main(){
    freopen("G:\\Git\\Algorithm-C-\\2.sort\\32.selection_sort\\input.txt", "rt", stdin);
    int a[100];
    int n, idx,i,j, tmp;

    scanf("%d", &n);

    for(i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    // selection sort
    for(i =0; i<n; i++){
        idx = i;

        // 자기 뒤부터 작은 값이 있는지 확인
        for(j = i+1; j<n ; j++){
            // 작은 값이 존재하면 idx를 j로 교체  
            if(a[j] < a[idx]) idx = j;
        }

        // 가장 작은 값과 i를 위치 바꿈
        tmp = a[i];
        a[i] = a[idx];
        a[idx] = tmp;
    }

    for(i=0; i<n; i++){
        printf("%d", a[i]);
    }

    return 0;
}   