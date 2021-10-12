#include <stdio.h>

int main(){
    freopen("G:\\Git\\Algorithm-C-\\1.base\\18.inter_floor_noise\\input.txt", "rt", stdin);

    int n, val, tmp, cnt=0, max=-2147000000;

    scanf("%d %d", &n, &val);

    for(int i=1; i<=n; i++){
        scanf("%d", &tmp);
        
        // 기준치를 초과하면 1초 추가
        if(tmp > val){
            cnt++;
        } else { //기준치를 초과하지 않으면 0으로 초기화
            cnt = 0;
        }

        // 만약 현재 초가 최장시간이라면  
        if(cnt > max){
            max = cnt;
        }
    }
    // 경보음이 한번도 울리지 않았다면
    if(max==0) printf("-1\n");
    else printf("%d\n", max);

    return 0;
}