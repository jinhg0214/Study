#include <stdio.h>
#include <stack>

using namespace std;

int main(){
    char input[31];
    stack<char> st;

    scanf("%s", &input);

    for(int i=0; input[i]!='\0'; i++){

        // ���1. "(" �Է�
        if(input[i] == '('){
            st.push('(');
        }
        else {
             // ���2. stack�� ����ִµ� ")"�� �Է�
            if(st.empty() && input[i] == ')'){
                printf("NO\n");
                return 0;
            }
            // ���3. stack�� ���ְ�, ")"�� �Է�
            else{
                st.pop();
            }
        }

       
    }

    // ���4. �Է��� �������� stack�� "("�� ��������
    if(!st.empty()){
        printf("NO\n");
    }
    else 
        printf("YES\n");

    return 0;
}