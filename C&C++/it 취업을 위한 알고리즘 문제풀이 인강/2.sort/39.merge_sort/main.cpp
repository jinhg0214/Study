#include <stdio.h>

int main(){
    freopen("G:\\Git\\Algorithm-C-\\2.sort\\39.merge_sort\\input.txt", "rt", stdin);


    // ������ �����͸� �̿��Ͽ� �� �� ����
    int a[101], p1=1, b[101], p2=1, c[101], p3=1, n, m;

    scanf("%d", &n);
    for(int i=1 ; i<=n; i++){
        scanf("%d", &a[i]);
    }

    scanf("%d", &m);
    for(int i=1 ; i<=m; i++){
        scanf("%d", &b[i]);
    }

    while(p1 <= n && p2 <= m){
        if(a[p1] < b[p2]){
            c[p3++] = a[p1++];   
        }
        else {
            c[p3++] = b[p2++];
        }
    }

    // a�迭�� �ڷᰡ ���� ���
    while(p1<=n){
        c[p3++] = a[p1++];
    }

    // b�迭 ''
    while(p2<=m){
        c[p3++] = b[p2++];
    } 

    for(int i=1; i<p3; i++){
        printf("%d ", c[i]);
    }

    return 0;

}