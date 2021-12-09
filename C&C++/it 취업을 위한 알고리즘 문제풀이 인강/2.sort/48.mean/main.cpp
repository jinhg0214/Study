#include <stdio.h>
#include <math.h>

// 평균과 가까운 값이 두개인 경우 그 중 큰값을 출력

int main(){
    freopen("G:\\Git\\Algorithm-C-\\2.sort\\48.mean\\input.txt","rt",stdin);
    int a[9][9], m[9], i, j, sum, avg, min, tmp, res;

    for(i=0;i<9;i++){
        sum=0;
        for(j=0;j<9;j++){
            scanf("%d", &a[i][j]);
            sum += a[i][j];
        }
        avg = (sum/9.0)+0.5;
        
        printf("%d ", avg);

        min = 2147000000;

        for(j=0; j<9; j++){
           
            tmp = abs(a[i][j]-avg);

            if(tmp < min){
                min = tmp;
                res = a[i][j];
            }

            // 평균이 차이가 같은 값이 두개일때, 큰 값을 취한다.
            else if(tmp == min){
                if(a[i][j] > res){
                    res = a[i][j];
                }
            }
        }
        printf("%d\n", res);


    }

    return 0;

}