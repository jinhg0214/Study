#include <stdio.h>

int a[101], tmp[101];

void merge_sort(int lt, int rt){

    int p1, p2, p3;
    int mid;

    if(lt < rt){

        mid = (lt+rt)/2;

        merge_sort(lt, mid);
        merge_sort(mid+1, rt);

        p1=lt;
        p2=mid+1;
        p3=lt;

        // º´ÇÕ
        while(p1 <= mid && p2 <= rt){
            if(a[p1] < a[p2]){
                tmp[p3++] = a[p1++];
            } else {
                tmp[p3++] = a[p2++];
            }
        }
        while(p1<=mid){
            tmp[p3++] = a[p1++];
        }
        while(p2<=rt){
            tmp[p3++] = a[p2++];
        }

        for(int i=lt; i<=rt; i++){
            a[i] = tmp[i];
        }



    }
}

int main(){

    freopen("G:\\Git\\Algorithm-C-\\3.recursion\\62.merge_sort\\input.txt","rt", stdin);

    int n, i;

    scanf("%d", &n);

    for(i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }

    merge_sort(1,n);

    for(i=1; i<=n; i++){
        printf("%d ", a[i]);
    }

    return 0;
}