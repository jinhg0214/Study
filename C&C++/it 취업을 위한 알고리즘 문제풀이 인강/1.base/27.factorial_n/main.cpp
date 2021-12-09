
#include <stdio.h>
#include <vector>

int main(){
    int n, tmp, i, j;

    scanf("%d", &n);

    std::vector<int> chk(n+1);  // 1~n 까지의 벡터 생성, 0으로 초기화

    // 2부터 카운팅
    for(i =2; i<n; i++){
        tmp=i;
        j=2; 

        while(1){
            if((tmp%j)==0){
                tmp = tmp/j;
                chk[j]++; // 발견된 인수 추가
            }
            else j++;

            if(tmp==1) break;
        }
    }
    
    printf("%d! = ", n);
    for(int i=2; i<=n; i++){
        if(chk[i]!=0) printf("%d ", chk[i]);
    }

    return 0;
}

/* 7!
7 * 6 * 5 * 4 * 3 * 2 * 1 
매 숫자마다 소인수 분해 후 체크 배열에 갯수 카운팅
= 7 * (2*3) * 5 *(2*2) * 3 * 2 * 1
*/