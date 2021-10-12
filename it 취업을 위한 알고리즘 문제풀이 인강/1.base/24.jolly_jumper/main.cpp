#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
// 정수 n가 입력되면, 차이가 정수 1~n-1까지의 값을 모두 가지는가?
// 1. check 배열을 만들어, 1~n-1까지의 값을 직접 체크

int main(){
    freopen("G:\\Git\\Algorithm-C-\\1.base\\24.jolly_jumper\\input.txt", "rt", stdin);
    int n, now, pre, pos; 

    // 값 입력 받기
    scanf("%d", &n);

    vector<int> chk(n);

    // 첫번째 값 읽기
    scanf("%d", &pre);

    // 두번째 값부터 n-1까지
    for(int i=1; i<n; i++){
        scanf("%d", &now);
        pos = abs(pre-now); 

        // 이웃한 두 값이 차이가 1~n-1에 존재하는가
        // 또한 chk 배열에 중복값이 없는지 체크
        if(pos<n && chk[pos] == 0){
            chk[pos] = 1;
        }

        else {
            printf("NO\n");
            return 0;
        }
        pre = now; // 다음 값으로 이동
    }

    printf("YES\n");

    return 0;
}