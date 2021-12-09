#include <stdio.h>

int main(){
    freopen("G:\\Git\\Algorithm-C-\\2.sort\\38.Inversion_sequence\\input.txt", "rt", stdin);
    
    int n, is[101], os[101], i, j, pos;

    scanf("%d", &n);

    for(i=1; i<=n; i++){
        scanf("%d", &is[i]);
    }

    for(i=n; i>=1; i--){
        pos = i;

        // is[i]¹ø ¸¸Å­ ¶¯±è 
        for(j=1; j<=is[i]; j++){
            os[pos] = os[pos+1];
            pos++;
        }

        os[pos] = i;

    }

    for(i=1; i<=n; i++){
        printf("%d ", os[i]);
    }


}