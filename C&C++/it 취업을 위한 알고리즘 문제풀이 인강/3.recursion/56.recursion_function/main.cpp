#include <stdio.h>

void printN(int n){
    if(n<1) return;

    printN(n-1);
    printf("%d ", n);
}

int main(){

    int n;
    scanf("%d", &n);

    printN(n);

    return 0;
}