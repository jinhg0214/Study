#include <stdio.h>

int cache[20];

int main(){
    freopen("G:\\Git\\Algorithm-C-\\2.sort\\37.LRU\\input.txt", "rt", stdin);

    int s, n, i, j, tmp, pos;

    scanf("%d %d",&s ,&n);
   
    for(i=0; i<n; i++){ // n회 반복
        scanf("%d", &tmp);

        pos = -1;

        // 캐시를 돌며 hit인지 확인
        for(j=0;j<s;j++){
            if(cache[j] == tmp){ // hit인 경우
                pos = j;
            }
        }

        // miss
        if(pos==-1){
            for(j=s-1; j>=1; j--){ // 앞으로 이동하면서 
                cache[j]=cache[j-1]; // 뒤로 한칸씩 땡김, 마지막 작업은 캐시에서 소멸
            }
        } 
        // hit
        else {
            // cache[pos] 를 0으로 땡기고 
            for(j=pos; j>=1; j--){  // pos 이전의 작업들을 한칸씩 뒤로 
                cache[j] = cache[j-1];
            }
            
        }
        // 가장 최신 작업을 맨 앞으로
        cache[0] = tmp;
    }

    for(i=0; i<s; i++) 
        printf("%d ", cache[i]);

    return 0;
}