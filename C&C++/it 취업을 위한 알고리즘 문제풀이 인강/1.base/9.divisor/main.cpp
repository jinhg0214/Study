#include <stdio.h>

int cnt[50001]; // 50001개 눈을 가진 체 생성

int main(){

    /* my answer (n^2의 시간 복잡도!)
    int n, cnt = 0;

    scanf("%d", &n);

    // 1 to N 까지의 자연수의 약수 개수 출력
    for(int i=1; i<=n; i++){ 
        cnt = 0;
        for(int j=1; j<-=; j++){
            if((i % j)==0){
                cnt++;
            }
        }
        printf("%d ",cnt);
    }
    */

    // 에라토스테네스의 체와 비슷한 방법 사용
    /*
    1을 약수로 가지는 수에++,
    2를 '' ++,
    ... 사용

    */
    
    int n;

    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j=j+i){  // j는 i의 배수
            cnt[j]++;
        }
    }

    for(int i=1; i<=n; i++){
        printf("%d ", cnt[i]);
    }

    return 0;
}