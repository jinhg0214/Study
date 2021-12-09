#include <stdio.h>

// 주어진 정수를 뒤집는 함수
// 1. 910 -> 19처럼 첫자리 부터 연속된 0은 무시한다 
// 자연수 크기는 100,000을 넘지 않음 

int reverse(int x){
    int res=0, tmp;
    while(x>0){
        tmp=x%10;
        res = res*10 + tmp;
        x=x/10;
    }
    return res;
}
/*
x       tmp     res     
3700    0       0
370     0       0
37      7       7
3       3       73       
*/

// 소수 판별 함수
// 1은 예외처리해주어야함!!!
bool isPrime(int x){

    if(x==1){
        return false;
    }

    for(int i=2; i<x; i++){
        if((x%i) == 0){
            return false;
        }
    }

    return true;
}

int main(){
    int n, num, reversed_num;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &num);
        reversed_num = reverse(num);
        if(isPrime(reversed_num)){
            printf("%d ", reversed_num);
        }
    }

    return 0;
}