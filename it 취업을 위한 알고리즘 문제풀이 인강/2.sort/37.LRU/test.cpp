#include <stdio.h>

int cache[20];

int main(){
    freopen("G:\\Git\\Algorithm-C-\\2.sort\\37.LRU\\input.txt", "rt", stdin);

    int size, n, i, j, tmp, pos;

    scanf("%d %d",&size ,&n);

    for(i=1; i<n+1; i++){
        scanf("%d", &tmp);

        pos = -1;

        // 캐시에 tmp값이 존재하는지 확인   
        for(j=0; j<size; j++){
            // 존재하면 hit
            if(cache[j] == tmp){
                pos = j;
            }
        }

        // 존재하지 않으면 miss
        if(pos==-1){
            // miss인 경우, 맨 앞에 tmp를 삽입 후, 모두 뒤로 미룬다
            // 마지막 원소는 그대로 삭제됨
            for(j=size-1; j>=1; j--){ // 뒤로 미룰땐 항상 뒤에서부터 앞으로 이동해야함
                cache[j] = cache[j-1];
            }
        }
        cache[0] = tmp;

    }


    return 0;
}