#include <stdio.h>

int main(){
    int n, tmp, j, cnt_2=0, cnt_5=0;

    scanf("%d", &n);

    // n!를 소인수 분해 후 개수 카운팅
    for(int i=2; i<=n; i++){
        tmp = i;
        j=2;

        while(1){
            if((tmp%j)==0){
                if(j==2) cnt_2++;
                else if(j==5) cnt_5++;
                
                tmp=tmp/j;
                
            }
            else{
                j++;
            }

            if(tmp==1) break;
        }
    }

    if(cnt_2 < cnt_2) printf("%d\n", cnt_2);
    else printf("%d\n", cnt_5);

    return 0;
}

/*
int 변수에 1000!을 넣고 직접 0을 세면 불가능!!(오버플로우)
소인수 분해 후 (2,5)의 개수 카운팅
*/