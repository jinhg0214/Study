#include <stdio.h>

int stack[100], top=-1;

void push(int x){
    stack[++top]=x;
}

int pop(){
    return stack[top--];
}

int main(){
    int n, k;
    char str[20]="0123456789ABCDEF"; // 2, 5, 8, 16 �ִ� 16���� 
    scanf("%d %d", &n, &k);

    while(n>0){
        push(n%k);
        n=n/k;
    }

    while(top != -1){
        printf("%c", str[pop()]);
    }
    return 0;
}