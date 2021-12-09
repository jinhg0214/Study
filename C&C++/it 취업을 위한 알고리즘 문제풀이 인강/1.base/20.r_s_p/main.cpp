#include <stdio.h>

int main(){
    freopen("G:\\Git\\Algorithm-C-\\1.base\\20.r_s_p\\input.txt", "rt", stdin);
    int n;
    int a[101], b[101];

    // n회 가위바위보 
    scanf("%d", &n);

    // a의 행동 
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }
    // b의 행동 
    for(int i=1; i<=n; i++){
        scanf("%d", &b[i]);
    }
    
    // 승리 판별
    for(int i=1; i<=n; i++){

        // 비겼을 경우
        if(a[i]==b[i]){printf("D\n");}

        // A가 이기는 경우들
        else if(a[i]==1 && b[i]==3){printf("A\n");} // 가위 > 보
        else if(a[i]==2 && b[i]==1){printf("A\n");} // 바위 > 가위
        else if(a[i]==3 && b[i]==2){printf("A\n");} // 보 > 바위

        // 그 외에는 B가 이기는 경우밖에 없음
        else printf("B\n");
    }

    return 0;
}