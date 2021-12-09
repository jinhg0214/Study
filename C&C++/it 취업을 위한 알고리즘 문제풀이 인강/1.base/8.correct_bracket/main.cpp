#include <stdio.h>

int main(){
    // 스택을 사용하는 문제지만, 사용하지 않고도 해결 가능함
    /* 
    - cnt = 0 '(' = +1, ')' = -1
    두 쌍이 제대로 맞다면 최종 결과가 0이 됨
    - 마지막에 0이라고 무조건 올바른 괄호가 아님!! ex) (()))( = 0
    즉, 음수가 되버리면 복구 불가능한 괄호임! -> NO
    */ 
    freopen("G:\\Git\\Algorithm-C-\\1.base\\8.correct_bracket\\input.txt", "rt", stdin);
    char a[100];
   
    int cnt = 0;
    scanf("%s", &a);

    for(int i=0; a[i]!='\0';i++){
        // ( = +1, ) = -1
        if(a[i]=='('){
            cnt++;
        } else if(a[i]==')'){
            cnt--;
        }

        // cnt가 음수라면 복구 불가 괄호
        if(cnt < 0){
            break;
        }
    }
    
    if(cnt == 0) printf("YES\n");
    else printf("NO\n");

    return 0;
}