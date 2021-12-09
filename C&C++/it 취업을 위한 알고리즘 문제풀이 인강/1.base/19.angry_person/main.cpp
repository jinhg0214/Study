#include <stdio.h>

int main(){
    freopen("G:\\Git\\Algorithm-C-\\1.base\\19.angry_person\\input.txt", "rt", stdin);
    int n, h[101], cnt=0, max;

    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        scanf("%d", &h[i]);
    }

    // 배열 뒤에서 부터 앞으로가면서 max값을 찾음 
    max = h[n]; 

    for(int i=n-1; i>=1; i--){
        // 만약 앞사람이 더 크면 분노유발자임
        if(h[i] > max){
            max = h[i];
            cnt++;
        }
    }

    printf("%d\n", cnt);

    return 0;

}