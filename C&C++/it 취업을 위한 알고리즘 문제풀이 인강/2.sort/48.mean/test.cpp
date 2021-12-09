#include <stdio.h>
#include <math.h>

#define n 9

int main(){
    freopen("G:\\Git\\Algorithm-C-\\2.sort\\48.mean\\input.txt","rt",stdin);

    int i, j, m[9], sum, mean, res, tmp;

    for(i=1; i<=n; i++){
        sum=0;

        for(j=1; j<=n; j++){
            scanf("%d", &m[j]);
            sum += m[j];
        }   
        mean = (sum/9.0)+0.5;    // 평균은 소수점 첫 번째 자리에서 반올림함

        printf("%d ", mean);

        tmp=2147000000;
        
        for(j=1; j<=n; j++){
            if(abs(m[j]-mean) < tmp){
                tmp = abs(m[j]-mean);
                res = m[j];
            }
        }

        printf("%d\n", res);
    }

    return 0;
}