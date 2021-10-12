#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    freopen("G:\\Git\\Algorithm-C-\\2.sort\\42.binary_search\\input.txt", "rt", stdin);

    int n, m;

    scanf("%d %d", &n, &m);

    vector<int> a(n);

    for(int i =0; i<n; i++){
        scanf("%d", &a[i]);
    }

    // a를 정렬
    sort(a.begin(), a.end());

    // 중간값과 계속 비교
    int lt=0, rt=n, mid, res;   // lt는 0으로, rt는 n으로 초기화
    
    while(1){
        mid = (lt+rt)/2;
        if(a[mid] == m){
            res = mid+1; // n+1번째 자리가 결과값
            break;
        } else if (a[mid] > m){
            rt = mid-1;
        } else {
            lt = mid+1;
        }
    }

    printf("%d", res);

}