#include <stdio.h>
#include <math.h>

// ��հ� ����� ���� �ΰ��� ��� �� �� ū���� ���

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

            // ����� ���̰� ���� ���� �ΰ��϶�, ū ���� ���Ѵ�.
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