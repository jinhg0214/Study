#include <stdio.h>
#include <algorithm>

/*
            1~45
    1~22           
1~11x   12~22o    
    12~16x   16~22o 
                ...

*/     
using namespace std;

int a[1001], n;


// dvd가 몇개까지 들어가는지 확인하는 함수
int Count(int sz){
    int i, cnt=1, sum=0;

    for(i=1; i<=n; i++){
        if(sum+a[i] > sz) {
            cnt++;
            sum=a[i];
        } else {
            sum += a[i];
        }
    }
    return cnt;
}


int main(){

    freopen("G:\\Git\\Algorithm-C-\\2.sort\\43.decision_algorithm\\input.txt", "rt", stdin);

    int m; // dvd의 개수
    int lt=0, rt, mid, cnt=0, res;

    scanf("%d %d", &n, &m);

    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
        rt= rt+a[i];
    }    

    while(lt <= rt){
        mid = (lt+rt)/2;

        if(Count(mid) <= m){
            res = mid;
            rt = mid-1;
        }
        else {
            lt = mid+1;
        }
    }
    printf("%d\n", res);


    return 0;

}
