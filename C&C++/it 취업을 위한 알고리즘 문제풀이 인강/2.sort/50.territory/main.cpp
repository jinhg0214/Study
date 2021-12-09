#include <stdio.h>

// 입력 값이 작으므로 4중 for문으로 해도됨

int t[51][51];


int main(){
    freopen("G:\\Git\\Algorithm-C-\\2.sort\\50.territory\\input.txt", "rt", stdin); 
    int w, h, tw, th, sum, max=-2147000000;

    scanf("%d %d", &h, &w);

    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            scanf("%d", &t[i][j]);
        }
    }

    scanf("%d %d", &th, &tw);

    for(int i=1; i<=h-th+1; i++){
        for(int j=1; j<=w-tw+1; j++){
            
            sum=0;

            for(int k=0; k<th; k++){
                for(int l=0; l<tw; l++){
                    sum += t[i+k][j+l];
                }
            }

            if(sum > max){
                max = sum;
            }
            
        }
    }

    printf("%d", max);

    return 0;
}