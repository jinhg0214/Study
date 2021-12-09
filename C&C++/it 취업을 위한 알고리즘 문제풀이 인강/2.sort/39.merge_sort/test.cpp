#include <stdio.h>

int main(){
    freopen("G:\\Git\\Algorithm-C-\\2.sort\\39.merge_sort\\input.txt", "rt", stdin);


    int a[101], b[101], merged[101];
    int p1=0, p2=0, p3=0, n, m;

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    scanf("%d", &m);
    for(int i=0; i<m; i++){
        scanf("%d", &b[i]);
    }

    while(p1<n && p2<m){

        if(a[p1] < b[p2]){
            merged[p3] = a[p1];
            p1++;
            p3++;
        } else {
            merged[p3] = b[p2];
            p2++;
            p3++;
        }
    }

    while(p1 < n){
        merged[p3] = a[p1];
        p1++;
        p3++;
    }

    while(p2 < m){
        merged[p3] = b[p2];
        p2++;
        p3++;
    }

    for(int i=0; i<p3; i++){
        printf("%d ", merged[i]);
    }

    return 0;

}