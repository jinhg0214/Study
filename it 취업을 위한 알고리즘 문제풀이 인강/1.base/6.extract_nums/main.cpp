#include <stdio.h>

int main(){
    // freopen("G:\\Git\\Algorithm-C-\\1.base\\6.extract_nums\\input.txt", "rt", stdin);
    char a[100];

    int result = 0, cnt = 0;

    scanf("%s", &a);

    for(int i=0; a[i] != '\0'; i++){ // a[i] 가 null 이 아닐때!
        if(a[i] >= 48 && a[i] <= 57){ // a[i]의 ascii가 숫자 
            result = result * 10 + (a[i]-48); // result를 왼쪽으로 한칸씩 옮김
        } 
    }

    printf("%d\n", result);

    // 약수의 개수 
    for(int i =1; i<= result; i++){
        if((result % i) == 0){
            cnt++;
        }
    }

    printf("%d\n", cnt);

    return 0;
}