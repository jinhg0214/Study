#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
    freopen("G:\\Git\\Algorithm-C-\\2.sort\\40.intersection\\input.txt", "rt", stdin);

    int n, m;

    scanf("%d", &n);
    int *a = new int[n];
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    sort(a, a+n);

    scanf("%d", &m);
    int *b = new int[m];
    for(int i=0; i<m; i++){
        scanf("%d", &b[i]);
    }

    sort(b, b+n);

    int *c = new int[n+m];

    int p1=0, p2=0, p3=0;

    while(p1<n && p2<m){
        if(a[p1]<b[p2]){
            p1++;
        } else if(b[p2] < a[p1]){
            p2++;
        } else {
            c[p3] = a[p1];
            p1++;
            p2++;
            p3++;
        }
    }

    for(int i=0; i<p3; i++){
        printf("%d ", c[i]);
    }

    return 0;
}