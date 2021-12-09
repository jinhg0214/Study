#include <stdio.h>
#include <stack>

using namespace std;

int main(){
    char input[31];
    stack<char> st;

    scanf("%s", &input);

    for(int i=0; input[i]!='\0'; i++){

        // 경우1. "(" 입력
        if(input[i] == '('){
            st.push('(');
        }
        else {
             // 경우2. stack이 비어있는데 ")"이 입력
            if(st.empty() && input[i] == ')'){
                printf("NO\n");
                return 0;
            }
            // 경우3. stack이 차있고, ")"이 입력
            else{
                st.pop();
            }
        }

       
    }

    // 경우4. 입력이 끝났지만 stack에 "("이 남아있음
    if(!st.empty()){
        printf("NO\n");
    }
    else 
        printf("YES\n");

    return 0;
}