#include <stdio.h>
#include <vector>
#include <algorithm>

    // 1. 두 집합을 정렬해서 a, b배열에 넣는다.
    // 2. 포인터 p1, p2, p3로 a,b,c 제어함
    // 3. a[p1] == b[p2]일 경우 c[p3]에 삽입후 c를 출력한다


using namespace std;

int main(){
    freopen("G:\\Git\\Algorithm-C-\\2.sort\\40.intersection\\input.txt", "rt", stdin);

    int n, m, i, j, p1=0, p2=0, p3=0;

    // 입력 받는 부분
    // a, b 배열을 정렬
    scanf("%d", &n);

    vector<int> a(n);
    for(i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    sort(a.begin(), a.end());

    scanf("%d", &m);

    vector<int> b(m), c(n+m);

    for(i=0; i<m; i++){
        scanf("%d", &b[i]);
    }

    sort(b.begin(), b.end());

    // 비교 후 같은 원소를 c에 삽입
    while(p1<n && p2<m){
        if(a[p1] == b[p2]){
            c[p3++] = a[p1++];
            p2++;
        } else if(a[p1] < b[p2]){
            p1++;
        } else 
            p2++;
    }

    for(i=0; i<p3; i++){
        printf("%d ", c[i]);
    }

    return 0;

}