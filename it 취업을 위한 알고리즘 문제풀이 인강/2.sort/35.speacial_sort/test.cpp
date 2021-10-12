#include <stdio.h>

int main(){
    freopen("G:\\Git\\Algorithm-C-\\2.sort\\35.speacial_sort\\input.txt", "rt", stdin);
    int n, a[101],i,j, tmp;

    scanf("%d", &n);

    for(i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    // 버블 정렬을 응용
    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            
            // 음수는 앞으로 보내고, 양수는 뒤로 보낸다
            if(a[j] > 0 && a[j+1] < 0){
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }

    for(i=0; i<n; i++){ 
        printf("%d ", a[i]);
    }

    return 0;

}