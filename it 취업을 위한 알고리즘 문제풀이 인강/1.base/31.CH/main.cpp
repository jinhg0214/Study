#include <stdio.h>

int main(){
    char a[10];

    scanf("%s", &a);

    // C_aH_b 형태로 입력 (1<= a, b <= 100)

    // ch

    // c2h4

    // c100h100


    int cn=0, hn=0, i, hpos;

    // h를 만나기 전까지
    // C가 단 한개 
    if(a[1] == 'H'){
        cn=1;
        hpos=1;
    }
    // C가 여러개
    else {
        // H를 만나면 끝남
        for(i=1; a[i] != 'H'; i++){
            cn = cn*10 +(a[i]-48);

        }
        hpos = i;
    }

    // H가 1개
    if(a[hpos+1] == '\0'){
        hn = 1;
    }
    // H가 여러개
    else {
        for(int i=hpos+1; a[i]!='\0'; i++){
            hn= hn*10 + (a[i]-48);
        }
    }
    printf("%d\n", cn*12 +hn);

    return 0;    
}