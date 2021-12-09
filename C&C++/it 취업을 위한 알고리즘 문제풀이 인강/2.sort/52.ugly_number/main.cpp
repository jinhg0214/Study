#include <stdio.h>

/*
n까지 소인수분해 -> Time Out

투포인트 알고리즘 이용


a[p2]*2
a[p3]*3
a[p5]*5
최소값을 a[pn]에 삽입
중복시 pn, pn' 모두 증가

*/
int a[1501];

int main(){
    int n, i, p2, p3, p5, min=2147000000;
    scanf("%d", &n);

    // 첫번째 숫자는 1
    a[1]=1;

    p2=p3=p5=1;

    for(i=2; i<=n; i++){
        // 먼저 a[p2]*2와 a[p3]*3을 비교 
        if(a[p2]*2 < a[p3]*3) min = a[p2]*2;
        else min = a[p3]*3;

        // min과 a[p5]*5를 비교
        if(a[p5]*5 < min) min = a[p5]*5;

        // 포인터 이동, 중복될 시 모두 증가
        if(a[p2]*2 == min) p2++;
        if(a[p3]*3 == min) p3++;
        if(a[p5]*5
         == min) p5++;

        a[i] = min;
    }

    printf("%d\n", a[n]);

    return 0;
}