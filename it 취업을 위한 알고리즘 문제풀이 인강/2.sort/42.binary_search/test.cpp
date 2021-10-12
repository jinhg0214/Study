#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
    int n, m;

    scanf("%d %d", &n, &m);

    int *a = new int[n];

    for(int i =0; i<n ;i++){
        scanf("%d", &a[i]);
    }

    sort(a,a+n);

    int lt, rt, mid, res;
    lt=0; 
    rt=n;
    
    while(lt<=rt){
        mid = (lt+rt)/2;

        if(a[mid] < m){
            lt = mid-1;
        } else if(a[mid] > m){
            rt = mid+1;
        } else {
            res = mid;
            break;
        }
    }

    printf("%d", res+1); // 0부터 카운팅 하므로 +1번째 
}