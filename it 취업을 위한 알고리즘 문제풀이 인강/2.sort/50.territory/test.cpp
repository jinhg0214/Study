#include <stdio.h>

int t[51][51];

int main(){
    freopen("G:\\Git\\Algorithm-C-\\2.sort\\50.territory\\input.txt", "rt", stdin); 

    int h, w, t_h, t_w, sum=0, res=0;

    int i, j, k, l;

    scanf("%d %d",&h, &w);

    for(i=1; i<=h; i++){
        for(j=1; j<=w; j++){
            scanf("%d", &t[i][j]);
        }
    }

    scanf("%d %d",&t_h, &t_w);

    for(i=1; i<=h-t_h+1; i++){
        for(j=1; j<=w-t_w+1; j++){
            
            sum = 0;

            for(k=0; k<t_h; k++){
                for(l=0; l<t_w; l++){
                    sum += t[i+k][j+l];
                }
            }

            if(sum > res) res = sum;

        }
    }

    printf("%d", res);

    return 0;
}