#include <stdio.h>

int main(){
    int n, a[101], i, j, idx, tmp;

    scanf("%d", &n);

    for(i=0;i<n;i++){
        scanf("%d", &a[i]);
    }

    for(i=0; i<n; i++){
        idx = i;

        // i~n ���� ���� ���� �� ã��
        for(j=i; j<n; j++){
            if(a[j] < a[idx]){
                idx = j;
            }
        }

        // �� ���ڸ��� swap
        tmp = a[i];
        a[i] = a[idx];
        a[idx] = tmp;
    }

    for(i=0; i<n; i++){
        printf("%d ", a[i]);
    }

}