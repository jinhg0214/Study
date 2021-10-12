#include <stdio.h>

// 에라토스테네스의 체 사용
// 큰 수의 소수 개수 체크할때 사용함
bool a[200001]={1};

int main(){
    int n;
    scanf("%d", &n);

    // 체를 생성후 초기화
    for(int i=2; i<=n; i++){
        a[i]=i;
    }

    // 2부터 시작해서 특정 수의 배수에 해당하는 수를 모두 지움
    for(int i=2; i<=n; i++){
        // 이미 지워진 수라면 건너뛴다.
        if(a[i]==0) continue; 

        // 지워진 숫자가 아니라면, 그 배수부터 출발하여 지운다
        for(int j=2*i; j<=n; j=j+i){
            a[j]=0; 
        }
    }

   
    int cnt=0;
    // 지워지지 않은 수를 체크
    for(int i=2; i<=n; i++){
        if(a[i]!=0) cnt++;
    }

    printf("%d", cnt);

    return 0;
}