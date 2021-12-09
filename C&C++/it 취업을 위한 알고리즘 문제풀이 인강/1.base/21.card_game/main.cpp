#include <stdio.h>

int main(){
    //freopen("G:\\Git\\Algorithm-C-\\1.base\\21.card_game\\input.txt", "rt", stdin);

    int a[10], b[10];
    int a_score = 0, b_score = 0;

    // 카드 입력 받기
    for(int i=0; i<10; i++){
        scanf("%d", &a[i]);
    }

    for(int i=0; i<10; i++){
        scanf("%d", &b[i]);
    }

    // 스코어 계산
    for(int i=0; i<10; i++){
        // a가 승리
        if(a[i] > b[i]){
            a_score += 3;
        } 
        // b가 승리
        else if (b[i] > a[i]){
            b_score += 3;
        } 
        // 동점
        else {
            a_score++;
            b_score++;
        }
    }
    // 결과 출력
    printf("%d %d\n",a_score, b_score);

    // 동점인 경우
    if(a_score==b_score){
        // 마지막으로 승부가 난 라운드로 결정
        for(int i=10; i>=0; i--){
            if(a[i] > b[i]) {
                printf("A\n");
                return 0;    
            }
            else if (b[i] > a[i]) {
                printf("B\n");
                return 0;
            }
        }
        // 모두 같은 경우
        printf("D\n");
        return 0;
    } 
    else if(a_score > b_score) printf("A\n");
    else if (b_score > a_score) printf("B\n");

    return 0;
}