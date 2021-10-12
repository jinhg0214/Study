// lastwin 변수를 하나 두고, 출력할 승자를 기록

#include <stdio.h>

int main(){
    freopen("G:\\Git\\Algorithm-C-\\1.base\\21.card_game\\input.txt", "rt", stdin);
    int A[10], B[10], as =0, bs=0, lw=0;


    // 카드 입력 받기
    for(int i=0; i<10; i++){
        scanf("%d", &A[i]);
    }

    for(int i=0; i<10; i++){
        scanf("%d", &B[i]);
    }

    // 점수 계산
    for(int i=0; i<10; i++){
        // a가 승리
        if(A[i] > B[i]){
            as += 3;
            lw = 1; // 1 = A를 출력
        }

        // b가 승리
        else if (B[i] > A[i]){
            bs += 3;
            lw = 2; // 2 = B를 출력
        } 
        // 동점
        else {
            as++;
            bs++;
        }
    }  

    // 결과 출력
    printf("%d %d\n", as, bs);

    if(as==bs){
        if(lw == 0) printf("D\n");
        else if(lw == 1) printf("A\n");
        else printf("B\n");
    }
    else if(as > bs) printf("A\n");
    else printf("B\n");

}