
// 자기 보다 앞에 있는 수중에 큰 수 세기? 개수가 아니라 등수임!!!
// i 보다 크거나 같은 수 카운팅 +1하기 !!

#include <stdio.h>
#include <vector>

using namespace std;

int main(){
    freopen("G:\\Git\\Algorithm-C-\\1.base\\26.marathon\\input.txt","rt",stdin);

    int n, cnt;

    scanf("%d", &n);

    vector<int> score(n+1);

    for(int i=1; i<=n; i++){
        scanf("%d", &score[i]);
    }

    // 1등은 그냥 출력
    printf("1 ");

    // 2등부터 계산
    for(int i=2; i<=n; i++){
        
        cnt=0;

        for(int j=i-1; j>=1 ; j--){
            if(score[j] >= score[i]) cnt++;
        }

        printf("%d ", cnt+1);
    }

    return 0;
}