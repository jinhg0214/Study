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

// DVD용량 내에 들어가는지 확인하는 함수
int Count(int s){
    int i, cnt=1, sum=0;
    for(i=1; i<n; i++){
        if(sum+a[i] > s){ // 녹화할 수 있는가?
            cnt++;  // 불가능 할 경우 새로운 dvd를 추가함
            sum=a[i];
        }    
        else 
            sum += a[i];
    }
    return cnt;
}

int a[1001], n;

int main(){

    freopen("G:\\Git\\Algorithm-C-\\2.sort\\43.decision_algorithm\\input.txt", "rt", stdin);

    int m, i, lt=1, rt=0, mid, res;

    scanf("%d %d", &n, &m);

    for(i=1; i<=n; i++){
        scanf("%d", &a[i]);
        rt = rt+a[i];   // 최대 재생 시간 
    }

    while(lt <= rt){
        mid = (lt+rt)/2;
        if(Count(mid)<=m){
            res = mid;
            rt=mid-1;
        } 
        else{
            lt = mid+1;
        }
    }
    printf("%d\n", res);


    return 0;

}