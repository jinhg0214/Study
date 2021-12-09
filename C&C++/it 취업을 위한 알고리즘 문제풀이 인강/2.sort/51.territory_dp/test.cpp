#include <stdio.h>

// dy[i][j] = dy[i][j-1] + dy[i-1][j] -dy[i-1][j-1]+ a[i][j]를 이용한 dynamic programming

int a[701][701], dy[701][701];

int main(){
    freopen("G:\\Git\\Algorithm-C-\\2.sort\\51.territory_dp\\input.txt", "rt", stdin); 

    int h, w, t_h, t_w, tmp, max=-2147000000;
    int i, j;

    scanf("%d %d", &h, &w);

    for(i=1; i<=h; i++){
        for(j=1; j<=w; j++){
            scanf("%d", &a[i][j]);
            dy[i][j] = dy[i][j-1] + dy[i-1][j] - dy[i-1][j-1] + a[i][j];
        }
    }

    scanf("%d %d", &t_h, &t_w);

    for(i=t_h; i<=h; i++){
        for(j=t_w; j<=w; j++){
            tmp = dy[i][j] -dy[i-t_h][j] - dy[i][j-t_w] + dy[i-t_h][j-t_w];

            if(tmp > max) max =tmp;
        }
    }
    printf("%d\n", max);

    return 0;
}